#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

using namespace std;

const string ROOT_DIR = string(getenv("HOME")) + "/Music/";
const string PATH_YT_DLP = "yt-dlp";
const string version = "1.1.0";

void makeDir(string dir) {
    string command = "mkdir -p \"" + dir + "\"";  
    system(command.c_str());
}

void download(string url, string dir, bool isVideo = false) {
    makeDir(dir);
    
    // check if vid or audio
    string cmd = isVideo ? PATH_YT_DLP + " -f bestvideo+bestaudio --merge-output-format mp4 \"" + url + "\" -o \"" + dir + "/%(title)s.%(ext)s\"":
                            PATH_YT_DLP + " -x --audio-format mp3 \"" + url + "\" -o \"" + dir + "/%(title)s.%(ext)s\"";
    int status = system(cmd.c_str());

    if (status == 0) {
        cout << "Download completed\nSaved in " << dir << endl;
    } else {
        cout << "Download failed" << endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Welcome to mucydr!" << endl;
        cout << "- mucydr --info" << endl;
        cout << "  For Info" << endl;
        cout << "A Youtube audio Downloader" << endl;
        return 1;
    }

    string command = argv[1];
    bool isVideo = (argc > 3 && string(argv[argc - 1]) == "--mp4");

    // First Argument 
    if (command == "-d" || command == "--download") { // d for download 
        if (argc < 3) {
            cout << "URL Not Found" << endl;
            return 1;
        }
        
        string url = argv[2];
        download(url, ROOT_DIR, isVideo);

    } else if (command == "-s" || command == "--save"){ // save in path you want
        if (argc < 4){
            cout << "Usage: mucydr -s <link> <\"dir\">" << endl;
            cout << "Download will save in" << ROOT_DIR << "/<dir>"<< endl;
            return 1;
        }
        string url = argv[2];
        string dirIn = argv[3];
        string dir = ROOT_DIR + dirIn;
        download(url, dir, isVideo);
    }
    else if (command == "-a" || command == "--album") { // a for album
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
        
        download(url, dir, isVideo);
    } 
    else if (command == "-v" || command == "--version") {
        cout << "mucydr v"<< version << endl;
        return 1;
    } 
    
    else if (command == "--info") {
        cout << "Info :" << endl;
        cout << "- mucydr -d <link>" << endl;
        cout << "  Download Audio from Youtube and save it in "<< ROOT_DIR << endl;
        cout << "- mucydr -s <link> <your_dir> " << endl;
        cout << "  Download audio from YouTube and save in whatever you want\n";
        cout << "- mucydr -a <link> <\"artist_name\"> <\"album_name\">" << endl;
        cout << "  Download audio from YouTube and save in new folder" << endl;
        cout << "- You can download mp4 use command \"--mp4\" at the end" << endl;
        cout << "This is an MP3 YouTube downloader using yt-dlp" << endl;
        cout << "GitHub: https://github.com/adamwahyuh/mucydr" << endl;
    } else {
        cout << "Unknown command: " << command << endl;
        return 1;
    }

    return 0;
}
