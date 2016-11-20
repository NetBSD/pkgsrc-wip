$NetBSD$

SDL_StartTextInput() does not seem to provide the keys as expected,
so work around the problem by using the key codes (this does not
ignore SDL_TEXTINPUT events, it handles the case when SDL_KEYDOWN
is sent instead).

It looks like devel/SDL2 must depend on inputmethod/ibus for
SDL_StartTextInput() to work as expected (*cringe*).  Alternatively,
we need to define X_HAVE_UTF8_STRING when compiling devel/SDL and
devel/SDL2, but the configure scripts don't provide a means to
enable this flag (and I could not get the input to work with this
flag - so I am not sure if the problem is solved in this case).

--- src/input.cpp.orig	2016-07-02 15:42:10.000000000 +0000
+++ src/input.cpp
@@ -1295,6 +1295,223 @@ Key_data input(const bool IS_O_RETURN)
                     }
                     break;
 
+                case SDLK_QUOTE:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data('"', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_COMMA:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data('<', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_MINUS:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data('_', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_PERIOD:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data('>', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_SLASH:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data('?', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_0:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data(')', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_1:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data('!', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_2:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data('@', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_3:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data('#', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_4:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data('$', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_5:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data('%', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_6:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data('^', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_7:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data('&', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_8:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data('*', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_9:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data('(', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_SEMICOLON:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data(':', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_EQUALS:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data('+', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_LEFTBRACKET:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data('{', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_BACKSLASH:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data('|', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_RIGHTBRACKET:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data('}', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_BACKQUOTE:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data('~', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                case SDLK_a:
+                case SDLK_b:
+                case SDLK_c:
+                case SDLK_d:
+                case SDLK_e:
+                case SDLK_f:
+                case SDLK_g:
+                case SDLK_h:
+                case SDLK_i:
+                case SDLK_j:
+                case SDLK_k:
+                case SDLK_l:
+                case SDLK_m:
+                case SDLK_n:
+                case SDLK_o:
+                case SDLK_p:
+                case SDLK_q:
+                case SDLK_r:
+                case SDLK_s:
+                case SDLK_t:
+                case SDLK_u:
+                case SDLK_v:
+                case SDLK_w:
+                case SDLK_x:
+                case SDLK_y:
+                case SDLK_z:
+                    if (IS_SHIFT_HELD && !is_done)
+                    {
+                        ret = Key_data(sdl_key-32, sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                    if (!is_done)
+                    {
+                        ret = Key_data(sdl_key, sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                        is_done = true;
+                    }
+                    break;
+
+                case SDLK_KP_DIVIDE:
+                    ret = Key_data('/', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                    is_done = true;
+                    break;
+                case SDLK_KP_MULTIPLY:
+                    ret = Key_data('*', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                    is_done = true;
+                    break;
+                case SDLK_KP_MINUS:
+                    ret = Key_data('-', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                    is_done = true;
+                    break;
+                case SDLK_KP_PLUS:
+                    ret = Key_data('+', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                    is_done = true;
+                    break;
+                case SDLK_KP_1:
+                    ret = Key_data('1', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                    is_done = true;
+                    break;
+                case SDLK_KP_2:
+                    ret = Key_data('2', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                    is_done = true;
+                    break;
+                case SDLK_KP_3:
+                    ret = Key_data('3', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                    is_done = true;
+                    break;
+                case SDLK_KP_4:
+                    ret = Key_data('4', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                    is_done = true;
+                    break;
+                case SDLK_KP_5:
+                    ret = Key_data('5', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                    is_done = true;
+                    break;
+                case SDLK_KP_6:
+                    ret = Key_data('6', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                    is_done = true;
+                    break;
+                case SDLK_KP_7:
+                    ret = Key_data('7', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                    is_done = true;
+                    break;
+                case SDLK_KP_8:
+                    ret = Key_data('8', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                    is_done = true;
+                    break;
+                case SDLK_KP_9:
+                    ret = Key_data('9', sdl_key, IS_SHIFT_HELD, IS_CTRL_HELD);
+                    is_done = true;
+                    break;
+
                 case SDLK_SPACE:
                 case SDLK_BACKSPACE:
                 case SDLK_TAB:
