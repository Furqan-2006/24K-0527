#include <iostream>
#include <vector>
using namespace std;

class MediaFile
{
protected:
    string filePath;
    int size;

public:
    MediaFile(const string &path, int s) : filePath(path), size(s) {}
    virtual ~MediaFile() {}
    virtual void play() const { cout << "Playing media file: " << filePath << endl; }
    virtual void stop() const { cout << "Stopping media file: " << filePath << endl; }
};

class VisualMedia : virtual public MediaFile
{
protected:
    int resolutionX, resolutionY;

public:
    VisualMedia(const string &path, int s, int x, int y)
        : MediaFile(path, s), resolutionX(x), resolutionY(y) {}
};

class AudioMedia : virtual public MediaFile
{
protected:
    int sampleRate;

public:
    AudioMedia(const string &path, int s, int rate)
        : MediaFile(path, s), sampleRate(rate) {}
};

class ImageFile : public VisualMedia
{
public:
    ImageFile(const string &path, int s, int x, int y)
        : MediaFile(path, s), VisualMedia(path, s, x, y) {}
    void play() const override { cout << "Displaying image: " << filePath << " at " << resolutionX << "x" << resolutionY << endl; }
};

class AudioFile : public AudioMedia
{
public:
    AudioFile(const string &path, int s, int rate)
        : MediaFile(path, s), AudioMedia(path, s, rate) {}
    void play() const override { cout << "Playing audio: " << filePath << " at " << sampleRate << "Hz" << endl; }
};

class VideoFile : public VisualMedia, public AudioMedia
{
public:
    VideoFile(const string &path, int s, int x, int y, int rate)
        : MediaFile(path, s), VisualMedia(path, s, x, y), AudioMedia(path, s, rate) {}
    void play() const override
    {
        cout << "Playing video: " << filePath << " at " << resolutionX << "x" << resolutionY << " and " << sampleRate << "Hz" << endl;
    }
};

int main()
{
    vector<MediaFile *> mediaLibrary;
    mediaLibrary.push_back(new ImageFile("image.jpg", 500, 1920, 1080));
    mediaLibrary.push_back(new AudioFile("song.mp3", 3000, 44100));
    mediaLibrary.push_back(new VideoFile("movie.mp4", 5000, 1920, 1080, 48000));

    for (auto media : mediaLibrary)
    {
        media->play();
        media->stop();
        cout << "--------------------\n";
    }

    for (auto media : mediaLibrary)
        delete media;

    return 0;
}