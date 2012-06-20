#ifndef LUA_GAME_H_
#define LUA_GAME_H_

namespace gameplay
{

// Lua bindings for Game.
int lua_Game__gc(lua_State* state);
int lua_Game_clear(lua_State* state);
int lua_Game_displayKeyboard(lua_State* state);
int lua_Game_exit(lua_State* state);
int lua_Game_frame(lua_State* state);
int lua_Game_getAccelerometerValues(lua_State* state);
int lua_Game_getAnimationController(lua_State* state);
int lua_Game_getAudioController(lua_State* state);
int lua_Game_getAudioListener(lua_State* state);
int lua_Game_getConfig(lua_State* state);
int lua_Game_getFrameRate(lua_State* state);
int lua_Game_getHeight(lua_State* state);
int lua_Game_getPhysicsController(lua_State* state);
int lua_Game_getState(lua_State* state);
int lua_Game_getViewport(lua_State* state);
int lua_Game_getWidth(lua_State* state);
int lua_Game_isMultiTouch(lua_State* state);
int lua_Game_keyEvent(lua_State* state);
int lua_Game_menu(lua_State* state);
int lua_Game_mouseEvent(lua_State* state);
int lua_Game_pause(lua_State* state);
int lua_Game_resume(lua_State* state);
int lua_Game_run(lua_State* state);
int lua_Game_setMultiTouch(lua_State* state);
int lua_Game_setViewport(lua_State* state);
int lua_Game_static_getAbsoluteTime(lua_State* state);
int lua_Game_static_getGameTime(lua_State* state);
int lua_Game_static_getInstance(lua_State* state);
int lua_Game_static_isVsync(lua_State* state);
int lua_Game_static_setVsync(lua_State* state);
int lua_Game_touchEvent(lua_State* state);

void luaRegister_Game();

}

#endif
