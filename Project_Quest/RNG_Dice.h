#ifndef RNG_DICE_H
#define RNG_DICE_H


class RNG_Dice
{
    public:
        RNG_Dice();
        virtual ~RNG_Dice();

    protected:
        unsigned short roll();
    private:
        struct Node *root;
};

#endif // RNG_DICE_H
