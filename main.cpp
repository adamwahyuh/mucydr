#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

using namespace std;

const string ROOT_DIR = string(getenv("HOME")) + "/Music/";
const string PATH_YT_DLP = "yt-dlp";

void makeDir(string dir) {
    string command = "mkdir -p \"" + dir + "\"";  
    system(command.c_str());
}

void download(string url, string dir) {
    makeDir(dir);

    string cmd = PATH_YT_DLP + " -x --audio-format mp3 \"" + url + "\" -o \"" + dir + "/%(title)s.%(ext)s\"";
    int status = system(cmd.c_str());

    if (status == 0) {
        cout << "Download completed\nSaved in " << dir << endl;
    } else {
        cout << "Download failed" << endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Welcome to mucydr" << endl;
        cout << "  mucydr -s <link> " << endl;
        cout << "  Download audio from YouTube without making folder\n";
        cout << "  mucydr -a <link> <\"artist_name\"> <\"album_name\">" << endl;
        cout << "  Download audio from YouTube and save in new folder" << endl;
        cout << "  mucydr --info" << endl;
        cout << "  Show help message" << endl;
        return 1;
    }

    string command = argv[1];

    if (command == "-s") {
        if (argc < 3) {
            cout << "URL Not Found" << endl;
            return 1;
        }
        
        string url = argv[2];
        download(url, ROOT_DIR);

    } else if (command == "-a") {
        if (argc < 5) {
            cout << "Usage: mucydr -a <link> <artist name> <album name>" << endl;
            return 1;
        }

        string url = argv[2];
        string artist = argv[3];

        // Combine album name if there are more than one word
        string album;
        for (int i = 4; i < argc; i++) {
            if (i > 4) album += " ";  // add space if 2 words or more
            album += argv[i];
        }

        string dir = ROOT_DIR + artist + "/" + album;
        
        download(url, dir);
    } 

    else if (command == "--info") {
        cout << "Info :" << endl;
        cout << "  mucydr -s <link> " << endl;
        cout << "  Download audio from YouTube without making folder\n";
        cout << "  mucydr -a <link> <\"artist_name\"> <\"album_name\">" << endl;
        cout << "  Download audio from YouTube and save in new folder" << endl;
        cout << "This is an MP3 YouTube downloader using yt-dlp" << endl;
        cout << "GitHub: https://github.com/adamwahyuh/mucydr" << endl;
    } else {
        cout << "Unknown command: " << command << endl;
        return 1;
    }

    return 0;
}
