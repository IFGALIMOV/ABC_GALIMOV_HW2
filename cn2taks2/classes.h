//
// Created by Alexander Matveev on 26.10.2021.
//

#ifndef CN2TAKS2_CLASSES_H
#define CN2TAKS2_CLASSES_H

#endif //CN2TAKS2_CLASSES_H
#ifndef classes_h
#define classes_h

// MARK: - Animal class

class Animal {
public:
    char *title;
    int weight;

    Animal (char *title, int weight) {
        this->title = title;
        this->weight = weight;
    }

    float getData () {
        int sum = 0;
        for (int i = 0; this->title[i] != '\0'; i++) {
            sum += int(this->title[i]);
        }
        return (float)sum / (float)this->weight;
    }
};

// MARK: - Additional classes

class Fish: public Animal {
public:
    FishHabitat habitat;

    Fish (char *title, int weight, FishHabitat habitat): Animal(title, weight) {
        this->habitat = habitat;
    }
};

class Bird: public Animal {
public:
    bool fly;

    Bird (char *title, int weight, bool fly): Animal(title, weight) {
        this->fly = fly;
    }
};

class Beast: public Animal {
public:
    Food food;

    Beast (char *title, int weight, Food food): Animal(title, weight) {
        this->food = food;
    }
};

// MARK: - Data class

class Data {
public:
    Fish *fishes;
    int fishesCount;
    Bird *birds;
    int birdsCount;
    Beast *beasts;
    int beatsCount;

    Data () {
        this->fishes = nullptr;
        this->birds = nullptr;
        this->beasts = nullptr;
    }

    void read () {
        // func for reading from file
    }

    void write () {
        // func for writing to file
    }

    void sortFishes () {
        int mid = fishesCount / 2;
        if (fishesCount % 2 == 1)
            fishesCount++;
        int h = 1;
        Fish *temp = (Fish*)malloc(fishesCount * sizeof(Fish));
        int step;
        while (h < fishesCount)
        {
            step = h;
            int i = 0;
            int j = mid;
            int k = 0;
            while (step <= mid)
            {
                while ((i < step) && (j < fishesCount) && (j < (mid + step)))
                {
                    if (fishes[i].getData() < fishes[j].getData())
                    {
                        temp[k] = fishes[i];
                        i++; k++;
                    }
                    else {
                        temp[k] = fishes[j];
                        j++;
                        k++;
                    }
                }
                while (i < step)
                {
                    temp[k] = fishes[i];
                    i++;
                    k++;
                }
                while ((j < (mid + step)) && (j<fishesCount))
                {
                    temp[k] = fishes[j];
                    j++;
                    k++;
                }
                step = step + h;
            }
            h = h * 2;
            for (i = 0; i<fishesCount; i++)
                fishes[i] = temp[i];
        }
    }

    void sortBirds () {
        int mid = birdsCount / 2;
        if (birdsCount % 2 == 1)
            birdsCount++;
        int h = 1;
        Bird *temp = (Bird*)malloc(birdsCount * sizeof(Bird));
        int step;
        while (h < birdsCount)
        {
            step = h;
            int i = 0;
            int j = mid;
            int k = 0;
            while (step <= mid)
            {
                while ((i < step) && (j < birdsCount) && (j < (mid + step)))
                {
                    if (birds[i].getData() < birds[j].getData())
                    {
                        temp[k] = birds[i];
                        i++; k++;
                    }
                    else {
                        temp[k] = birds[j];
                        j++;
                        k++;
                    }
                }
                while (i < step)
                {
                    temp[k] = birds[i];
                    i++;
                    k++;
                }
                while ((j < (mid + step)) && (j<birdsCount))
                {
                    temp[k] = birds[j];
                    j++;
                    k++;
                }
                step = step + h;
            }
            h = h * 2;
            for (i = 0; i<birdsCount; i++)
                birds[i] = temp[i];
        }
    }

    void sortBeats () {
        int mid = beatsCount / 2;
        if (beatsCount % 2 == 1)
            beatsCount++;
        int h = 1;
        Beast *temp = (Beast*)malloc(beatsCount * sizeof(Beast));
        int step;
        while (h < beatsCount)
        {
            step = h;
            int i = 0;
            int j = mid;
            int k = 0;
            while (step <= mid)
            {
                while ((i < step) && (j < beatsCount) && (j < (mid + step)))
                {
                    if (beasts[i].getData() < beasts[j].getData())
                    {
                        temp[k] = beasts[i];
                        i++; k++;
                    }
                    else {
                        temp[k] = beasts[j];
                        j++;
                        k++;
                    }
                }
                while (i < step)
                {
                    temp[k] = beasts[i];
                    i++;
                    k++;
                }
                while ((j < (mid + step)) && (j<beatsCount))
                {
                    temp[k] = beasts[j];
                    j++;
                    k++;
                }
                step = step + h;
            }
            h = h * 2;
            for (i = 0; i<beatsCount; i++)
                beasts[i] = temp[i];
        }
    }
};

#endif /* classes_h */
