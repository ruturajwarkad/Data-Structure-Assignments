#include <iostream>


using namespace std;

struct Song {
    int s_id;
    string title;
    string artist;
    Song* ns;
};

class Playlist {
    Song* head;

public:
    Playlist() {
        head = NULL;
    }

    // Function for single song
    void printsong(Song* s) {
        cout << s->s_id << "\t" << s->title << "\t" << s->artist << "\n";
    }

    // Function for all songs
    void playsong() {
        Song* p = head;
        while (p) {
            printsong(p);
            p = p->ns;
        }
    }

    // Function for adding song at the end
    void addsong(string t, string a) {
        Song* ns = new Song;
        if (!ns) return;  // Memory allocation failed
        ns->s_id = rand() % 1000;
        ns->title = t;
        ns->artist = a;
        ns->ns = NULL;

        if (!head) {
            head = ns;
            return;
        }

        Song* p = head;
        while (p->ns) {
            p = p->ns;
        }
        p->ns = ns;
    }

    // Function for adding song at beginning
    void addSongBeginning(string t, string a) {
        Song* ns = new Song;
        ns->s_id = rand() % 1000;
        ns->title = t;
        ns->artist = a;
        ns->ns = head;
        head = ns;
    }

    // Function for adding song by title (sorted order)
    void addSongSorted(string t, string a) {
        Song* ns = new Song;
        ns->s_id = rand() % 1000;
        ns->title = t;
        ns->artist = a;
        ns->ns = NULL;

        if (!head || head->title > t) {
            ns->ns = head;
            head = ns;
            return;
        }

        Song* p = head;
        while (p->ns && p->ns->title < t) {
            p = p->ns;
        }
        ns->ns = p->ns;
        p->ns = ns;
    }

    // Function for deleteing song by title
    void removeSongByTitle(string t) {
        if (!head) return;
        Song* p = head;
        Song* prev = NULL;

        while (p && p->title != t) {
            prev = p;
            p = p->ns;
        }

        if (!p) return; // Song not found

        if (!prev) {
            head = p->ns;
        } else {
            prev->ns = p->ns;
        }
        delete p;
    }

    // Function for counting all songs
    int countSongs() {
        int count = 0;
        Song* p = head;
        while (p) {
            count++;
            p = p->ns;
        }
        return count;
    }

    // Function for counting songs by title 
    int countSongsByTitle(string t) {
        int count = 0;
        Song* p = head;
        while (p) {
            if (p->title == t) count++;
            p = p->ns;
        }
        return count;
    }

    // Function for searching song by title
    Song* searchSongByTitle(string t) {
        Song* p = head;
        while (p) {
            if (p->title == t) return p;
            p = p->ns;
        }
        return NULL;
    }

    // Function to edit song's title
    void editSongTitle(string oldTitle, string newTitle) {
        Song* p = searchSongByTitle(oldTitle);
        if (p) {
            p->title = newTitle;
        }
    }

    // Function to edit song's artist
    void editSongArtist(string title, string newArtist) {
        Song* p = searchSongByTitle(title);
        if (p) {
            p->artist = newArtist;
        }
    }
};

int main() {
    Playlist L1;

    // Adding songs
    L1.addsong("Lag Ja Gale Se Phir", "Lata Mangeshkar");
    L1.addsong("Yeh Sham Mastani", "Kishore Kumar");
    L1.addsong("Bade Achhe Lagte Hain", "Amit Kumar");
    L1.addsong("Tere Bina Zindagi Se", "Kishore Kumar");
    L1.addSongBeginning("Ek Ajnabee Haseena Se", "R.D. Burman");
    L1.addSongSorted("Kora Kagaz Tha Yeh Man Mera", "Kishore Kumar");


    // Playing all songs
    cout << "All Songs:\n";
    L1.playsong();

    // Total songs
    cout << "\nTotal Songs: " << L1.countSongs() << endl;

    // Edit song title
    L1.editSongTitle("Kora Kagaz Tha Yeh Man Mera", "Tum Aa Gaye Ho Noor Aa Gaya");
    cout << "\nAfter Editing Title:\n";
    L1.playsong();

    // Remove a song
    L1.removeSongByTitle("Tere Bina Zindagi Se");
    cout << "\nAfter Removing 'Tere Bina Zindagi Se':\n";
    L1.playsong();

    return 0;
}