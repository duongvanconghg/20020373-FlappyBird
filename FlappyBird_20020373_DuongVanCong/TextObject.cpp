#include "TextObject.h"


TextObject::TextObject(void)
{
    text_color_.r = 255;
    text_color_.g = 255;
    text_color_.b = 255;
}


TextObject::~TextObject(void)
{
}


bool TextObject::loadFromRenderedText(TTF_Font* gFont, SDL_Renderer* screen)
{
    //ket xuat be mat van ban
    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, str_val_.c_str(), text_color_);
    if (textSurface != NULL)
    {
        //tao ket cau tu cac pixel be mat
        texture_ = SDL_CreateTextureFromSurface(screen, textSurface);
        if (texture_ != NULL)
        {
            //nhan kich thuoc hinh anh
            width_ = textSurface->w;
            height_ = textSurface->h;
        }

        //loai bo be mat cu
        SDL_FreeSurface(textSurface);
    }

    //tra ve thanh cong
    return texture_ != NULL;
}

void TextObject::Free()
{
    if (texture_ != NULL)
    {
        SDL_DestroyTexture(texture_);
        texture_ = NULL;
    }
}

void TextObject::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
    text_color_.r = red;
    text_color_.g = green;
    text_color_.b = blue;
}

void TextObject::setColor(int type)
{
    if (type == RED_TEXT)
    {
        SDL_Color color = { 255, 0, 0 };
        text_color_ = color;
    }
    else if (type == WHITE_TEXT)
    {
        SDL_Color color = { 255, 255, 255 };
        text_color_ = color;
    }
    else
    {
        SDL_Color color = { 0, 0, 0 };
        text_color_ = color;
    }
}
void TextObject::RenderText(SDL_Renderer* screen, int x, int y, SDL_Rect* clip /* = NULL */, double angle /* = 0.0 */, SDL_Point* center /* = NULL */, SDL_RendererFlip flip /* = SDL_FLIP_NONE */)
{
    //dat khong gian ket xuat hien thi ra man hinh
    SDL_Rect renderQuad = { x, y, width_, height_ };

    //dat kich thuoc chiet xuat clip
    if (clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //ket xuat man hinh
    SDL_RenderCopyEx(screen, texture_, clip, &renderQuad, angle, center, flip);
}
