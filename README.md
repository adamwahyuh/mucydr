# 🎵 mucydr - YouTube Audio & Video Downloader  

**mucydr** is a simple command-line tool built with C++ that allows you to download audio (MP3) or video (MP4) from YouTube using `yt-dlp`. It also supports organizing downloads by **Artist** and **Album** for better file management.  

## 📌 Features  
✔️ Download **audio (MP3)** or **video (MP4)** from YouTube  
✔️ Save files directly to the `~/Music` directory  
✔️ Organize downloads into **Artist/Album** folders  

## 🚀 Usage  

### 🔹 Download and save to `~/Music`  
```sh
mucydr -d <link>
```
The audio file will be saved in `~/Music/` as an MP3.  

### 🔹 Download as **MP4 video**  
```sh
mucydr -d <link> --mp4
```
The video file will be saved in `~/Music/` as an MP4.  

### 🔹 Download and save to `~/Music/dir`  
```sh
mucydr -s <link> <dir>
```
The audio file will be saved in `~/Music/dir` as an MP3.

### 🔹 Download as **MP4 video**  
```sh
mucydr -s <link> --mp4
```
The video file will be saved in `~/Music/dir/<file_name>` as an MP4. 

### 🔹 Download and organize by **Artist/Album**  
```sh
mucydr -a <link> <Artist> <Album>
```
The audio file will be saved in the following structure:  
```
~/Music/Artist/Album/<file_audio>.mp3
```

### 🔹 Download **video** with Artist/Album structure  
```sh
mucydr -a <link> <Artist> <Album> --mp4
```
The video file will be saved as:  
```
~/Music/Artist/Album/<file_video>.mp4
```

---

🔥 **Now you can easily download and organize YouTube audio & video using mucydr!** 🚀
