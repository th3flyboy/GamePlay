#include "Base.h"
#include "ScriptController.h"
#include "Label.h"
#include "lua_Label.h"
#include "lua_Global.h"

namespace gameplay
{

void luaRegister_Label()
{
    ScriptController* sc = ScriptController::getInstance();

    const luaL_Reg lua_members[] = 
    {
        {"addListener", lua_Label_addListener},
        {"addRef", lua_Label_addRef},
        {"createAnimation", lua_Label_createAnimation},
        {"createAnimationFromBy", lua_Label_createAnimationFromBy},
        {"createAnimationFromTo", lua_Label_createAnimationFromTo},
        {"destroyAnimation", lua_Label_destroyAnimation},
        {"disable", lua_Label_disable},
        {"enable", lua_Label_enable},
        {"getAlignment", lua_Label_getAlignment},
        {"getAnimation", lua_Label_getAnimation},
        {"getAnimationPropertyComponentCount", lua_Label_getAnimationPropertyComponentCount},
        {"getAnimationPropertyValue", lua_Label_getAnimationPropertyValue},
        {"getAutoHeight", lua_Label_getAutoHeight},
        {"getAutoWidth", lua_Label_getAutoWidth},
        {"getBorder", lua_Label_getBorder},
        {"getBounds", lua_Label_getBounds},
        {"getClip", lua_Label_getClip},
        {"getClipBounds", lua_Label_getClipBounds},
        {"getConsumeTouchEvents", lua_Label_getConsumeTouchEvents},
        {"getCursorColor", lua_Label_getCursorColor},
        {"getCursorRegion", lua_Label_getCursorRegion},
        {"getCursorUVs", lua_Label_getCursorUVs},
        {"getFont", lua_Label_getFont},
        {"getFontSize", lua_Label_getFontSize},
        {"getHeight", lua_Label_getHeight},
        {"getID", lua_Label_getID},
        {"getImageColor", lua_Label_getImageColor},
        {"getImageRegion", lua_Label_getImageRegion},
        {"getImageUVs", lua_Label_getImageUVs},
        {"getMargin", lua_Label_getMargin},
        {"getOpacity", lua_Label_getOpacity},
        {"getPadding", lua_Label_getPadding},
        {"getRefCount", lua_Label_getRefCount},
        {"getSkinColor", lua_Label_getSkinColor},
        {"getSkinRegion", lua_Label_getSkinRegion},
        {"getState", lua_Label_getState},
        {"getStyle", lua_Label_getStyle},
        {"getText", lua_Label_getText},
        {"getTextAlignment", lua_Label_getTextAlignment},
        {"getTextColor", lua_Label_getTextColor},
        {"getTextRightToLeft", lua_Label_getTextRightToLeft},
        {"getWidth", lua_Label_getWidth},
        {"getX", lua_Label_getX},
        {"getY", lua_Label_getY},
        {"getZIndex", lua_Label_getZIndex},
        {"isEnabled", lua_Label_isEnabled},
        {"release", lua_Label_release},
        {"setAlignment", lua_Label_setAlignment},
        {"setAnimationPropertyValue", lua_Label_setAnimationPropertyValue},
        {"setAutoHeight", lua_Label_setAutoHeight},
        {"setAutoWidth", lua_Label_setAutoWidth},
        {"setBorder", lua_Label_setBorder},
        {"setBounds", lua_Label_setBounds},
        {"setConsumeTouchEvents", lua_Label_setConsumeTouchEvents},
        {"setCursorColor", lua_Label_setCursorColor},
        {"setCursorRegion", lua_Label_setCursorRegion},
        {"setFont", lua_Label_setFont},
        {"setFontSize", lua_Label_setFontSize},
        {"setImageColor", lua_Label_setImageColor},
        {"setImageRegion", lua_Label_setImageRegion},
        {"setMargin", lua_Label_setMargin},
        {"setOpacity", lua_Label_setOpacity},
        {"setPadding", lua_Label_setPadding},
        {"setPosition", lua_Label_setPosition},
        {"setSize", lua_Label_setSize},
        {"setSkinColor", lua_Label_setSkinColor},
        {"setSkinRegion", lua_Label_setSkinRegion},
        {"setState", lua_Label_setState},
        {"setStyle", lua_Label_setStyle},
        {"setText", lua_Label_setText},
        {"setTextAlignment", lua_Label_setTextAlignment},
        {"setTextColor", lua_Label_setTextColor},
        {"setTextRightToLeft", lua_Label_setTextRightToLeft},
        {"setZIndex", lua_Label_setZIndex},
        {NULL, NULL}
    };
    const luaL_Reg lua_statics[] = 
    {
        {"ANIMATE_OPACITY", lua_Label_static_ANIMATE_OPACITY},
        {"ANIMATE_POSITION", lua_Label_static_ANIMATE_POSITION},
        {"ANIMATE_POSITION_X", lua_Label_static_ANIMATE_POSITION_X},
        {"ANIMATE_POSITION_Y", lua_Label_static_ANIMATE_POSITION_Y},
        {"ANIMATE_SIZE", lua_Label_static_ANIMATE_SIZE},
        {"ANIMATE_SIZE_HEIGHT", lua_Label_static_ANIMATE_SIZE_HEIGHT},
        {"ANIMATE_SIZE_WIDTH", lua_Label_static_ANIMATE_SIZE_WIDTH},
        {NULL, NULL}
    };
    std::vector<std::string> scopePath;

    sc->registerClass("Label", lua_members, NULL, lua_Label__gc, lua_statics, scopePath);
}

static Label* getInstance(lua_State* state)
{
    void* userdata = luaL_checkudata(state, 1, "Label");
    luaL_argcheck(state, userdata != NULL, 1, "'Label' expected.");
    return (Label*)((ScriptController::LuaObject*)userdata)->instance;
}

int lua_Label__gc(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                void* userdata = luaL_checkudata(state, 1, "Label");
                luaL_argcheck(state, userdata != NULL, 1, "'Label' expected.");
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)userdata;
                if (object->owns)
                {
                    Label* instance = (Label*)object->instance;
                    SAFE_RELEASE(instance);
                }
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_addListener(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TUSERDATA &&
                lua_type(state, 3) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                void* userdata2 = ScriptController::getInstance()->getObjectPointer(2, "ControlListener");
                if (!userdata2)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'Control::Listener' for parameter 2.");
                    lua_error(state);
                }
                Control::Listener* param1 = (Control::Listener*)((ScriptController::LuaObject*)userdata2)->instance;

                // Get parameter 2 off the stack.
                int param2 = (int)luaL_checkint(state, 3);

                Label* instance = getInstance(state);
                instance->addListener(param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_addRef(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                instance->addRef();
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_createAnimation(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING &&
                lua_type(state, 3) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                const char* param1 = luaL_checkstring(state, 2);

                // Get parameter 2 off the stack.
                const char* param2 = luaL_checkstring(state, 3);

                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)instance->createAnimation(param1, param2);
                object->owns = false;
                luaL_getmetatable(state, "Animation");
                lua_setmetatable(state, -2);

                return 1;
            }
            else if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING &&
                lua_type(state, 3) == LUA_TUSERDATA)
            {
                // Get parameter 1 off the stack.
                const char* param1 = luaL_checkstring(state, 2);

                // Get parameter 2 off the stack.
                void* userdata3 = ScriptController::getInstance()->getObjectPointer(3, "Properties");
                if (!userdata3)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'Properties' for parameter 3.");
                    lua_error(state);
                }
                Properties* param2 = (Properties*)((ScriptController::LuaObject*)userdata3)->instance;

                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)instance->createAnimation(param1, param2);
                object->owns = false;
                luaL_getmetatable(state, "Animation");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 7:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING &&
                lua_type(state, 3) == LUA_TNUMBER &&
                lua_type(state, 4) == LUA_TNUMBER &&
                (lua_type(state, 5) == LUA_TTABLE || lua_type(state, 5) == LUA_TLIGHTUSERDATA) &&
                (lua_type(state, 6) == LUA_TTABLE || lua_type(state, 6) == LUA_TLIGHTUSERDATA) &&
                lua_type(state, 7) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                const char* param1 = luaL_checkstring(state, 2);

                // Get parameter 2 off the stack.
                int param2 = (int)luaL_checkint(state, 3);

                // Get parameter 3 off the stack.
                unsigned int param3 = (unsigned int)luaL_checkunsigned(state, 4);

                // Get parameter 4 off the stack.
                unsigned long* param4 = ScriptController::getInstance()->getUnsignedLongPointer(5);

                // Get parameter 5 off the stack.
                float* param5 = ScriptController::getInstance()->getFloatPointer(6);

                // Get parameter 6 off the stack.
                Curve::InterpolationType param6 = (Curve::InterpolationType)lua_enumFromString_CurveInterpolationType(luaL_checkstring(state, 7));

                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)instance->createAnimation(param1, param2, param3, param4, param5, param6);
                object->owns = false;
                luaL_getmetatable(state, "Animation");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 9:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING &&
                lua_type(state, 3) == LUA_TNUMBER &&
                lua_type(state, 4) == LUA_TNUMBER &&
                (lua_type(state, 5) == LUA_TTABLE || lua_type(state, 5) == LUA_TLIGHTUSERDATA) &&
                (lua_type(state, 6) == LUA_TTABLE || lua_type(state, 6) == LUA_TLIGHTUSERDATA) &&
                (lua_type(state, 7) == LUA_TTABLE || lua_type(state, 7) == LUA_TLIGHTUSERDATA) &&
                (lua_type(state, 8) == LUA_TTABLE || lua_type(state, 8) == LUA_TLIGHTUSERDATA) &&
                lua_type(state, 9) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                const char* param1 = luaL_checkstring(state, 2);

                // Get parameter 2 off the stack.
                int param2 = (int)luaL_checkint(state, 3);

                // Get parameter 3 off the stack.
                unsigned int param3 = (unsigned int)luaL_checkunsigned(state, 4);

                // Get parameter 4 off the stack.
                unsigned long* param4 = ScriptController::getInstance()->getUnsignedLongPointer(5);

                // Get parameter 5 off the stack.
                float* param5 = ScriptController::getInstance()->getFloatPointer(6);

                // Get parameter 6 off the stack.
                float* param6 = ScriptController::getInstance()->getFloatPointer(7);

                // Get parameter 7 off the stack.
                float* param7 = ScriptController::getInstance()->getFloatPointer(8);

                // Get parameter 8 off the stack.
                Curve::InterpolationType param8 = (Curve::InterpolationType)lua_enumFromString_CurveInterpolationType(luaL_checkstring(state, 9));

                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)instance->createAnimation(param1, param2, param3, param4, param5, param6, param7, param8);
                object->owns = false;
                luaL_getmetatable(state, "Animation");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 3, 7 or 9).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_createAnimationFromBy(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 7:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING &&
                lua_type(state, 3) == LUA_TNUMBER &&
                (lua_type(state, 4) == LUA_TTABLE || lua_type(state, 4) == LUA_TLIGHTUSERDATA) &&
                (lua_type(state, 5) == LUA_TTABLE || lua_type(state, 5) == LUA_TLIGHTUSERDATA) &&
                lua_type(state, 6) == LUA_TSTRING &&
                lua_type(state, 7) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                const char* param1 = luaL_checkstring(state, 2);

                // Get parameter 2 off the stack.
                int param2 = (int)luaL_checkint(state, 3);

                // Get parameter 3 off the stack.
                float* param3 = ScriptController::getInstance()->getFloatPointer(4);

                // Get parameter 4 off the stack.
                float* param4 = ScriptController::getInstance()->getFloatPointer(5);

                // Get parameter 5 off the stack.
                Curve::InterpolationType param5 = (Curve::InterpolationType)lua_enumFromString_CurveInterpolationType(luaL_checkstring(state, 6));

                // Get parameter 6 off the stack.
                unsigned long param6 = (unsigned long)luaL_checkunsigned(state, 7);

                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)instance->createAnimationFromBy(param1, param2, param3, param4, param5, param6);
                object->owns = false;
                luaL_getmetatable(state, "Animation");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 7).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_createAnimationFromTo(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 7:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING &&
                lua_type(state, 3) == LUA_TNUMBER &&
                (lua_type(state, 4) == LUA_TTABLE || lua_type(state, 4) == LUA_TLIGHTUSERDATA) &&
                (lua_type(state, 5) == LUA_TTABLE || lua_type(state, 5) == LUA_TLIGHTUSERDATA) &&
                lua_type(state, 6) == LUA_TSTRING &&
                lua_type(state, 7) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                const char* param1 = luaL_checkstring(state, 2);

                // Get parameter 2 off the stack.
                int param2 = (int)luaL_checkint(state, 3);

                // Get parameter 3 off the stack.
                float* param3 = ScriptController::getInstance()->getFloatPointer(4);

                // Get parameter 4 off the stack.
                float* param4 = ScriptController::getInstance()->getFloatPointer(5);

                // Get parameter 5 off the stack.
                Curve::InterpolationType param5 = (Curve::InterpolationType)lua_enumFromString_CurveInterpolationType(luaL_checkstring(state, 6));

                // Get parameter 6 off the stack.
                unsigned long param6 = (unsigned long)luaL_checkunsigned(state, 7);

                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)instance->createAnimationFromTo(param1, param2, param3, param4, param5, param6);
                object->owns = false;
                luaL_getmetatable(state, "Animation");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 7).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_destroyAnimation(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                instance->destroyAnimation();
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                const char* param1 = luaL_checkstring(state, 2);

                Label* instance = getInstance(state);
                instance->destroyAnimation(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1 or 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_disable(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                instance->disable();
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_enable(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                instance->enable();
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getAlignment(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                Control::Alignment result = instance->getAlignment();

                // Push the return value onto the stack.
                lua_pushstring(state, lua_stringFromEnum_ControlAlignment(result).c_str());

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getAnimation(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)instance->getAnimation();
                object->owns = false;
                luaL_getmetatable(state, "Animation");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                const char* param1 = luaL_checkstring(state, 2);

                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)instance->getAnimation(param1);
                object->owns = false;
                luaL_getmetatable(state, "Animation");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1 or 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getAnimationPropertyComponentCount(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                int param1 = (int)luaL_checkint(state, 2);

                Label* instance = getInstance(state);
                unsigned int result = instance->getAnimationPropertyComponentCount(param1);

                // Push the return value onto the stack.
                lua_pushunsigned(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getAnimationPropertyValue(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TNUMBER &&
                lua_type(state, 3) == LUA_TUSERDATA)
            {
                // Get parameter 1 off the stack.
                int param1 = (int)luaL_checkint(state, 2);

                // Get parameter 2 off the stack.
                void* userdata3 = ScriptController::getInstance()->getObjectPointer(3, "AnimationValue");
                if (!userdata3)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'AnimationValue' for parameter 3.");
                    lua_error(state);
                }
                AnimationValue* param2 = (AnimationValue*)((ScriptController::LuaObject*)userdata3)->instance;

                Label* instance = getInstance(state);
                instance->getAnimationPropertyValue(param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getAutoHeight(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                bool result = instance->getAutoHeight();

                // Push the return value onto the stack.
                lua_pushboolean(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getAutoWidth(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                bool result = instance->getAutoWidth();

                // Push the return value onto the stack.
                lua_pushboolean(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getBorder(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)&(instance->getBorder());
                object->owns = false;
                luaL_getmetatable(state, "ThemeSideRegions");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                Control::State param1 = (Control::State)lua_enumFromString_ControlState(luaL_checkstring(state, 2));

                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)&(instance->getBorder(param1));
                object->owns = false;
                luaL_getmetatable(state, "ThemeSideRegions");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1 or 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getBounds(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)&(instance->getBounds());
                object->owns = false;
                luaL_getmetatable(state, "Rectangle");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getClip(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)&(instance->getClip());
                object->owns = false;
                luaL_getmetatable(state, "Rectangle");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getClipBounds(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)&(instance->getClipBounds());
                object->owns = false;
                luaL_getmetatable(state, "Rectangle");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getConsumeTouchEvents(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                bool result = instance->getConsumeTouchEvents();

                // Push the return value onto the stack.
                lua_pushboolean(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getCursorColor(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                Control::State param1 = (Control::State)lua_enumFromString_ControlState(luaL_checkstring(state, 2));

                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)&(instance->getCursorColor(param1));
                object->owns = false;
                luaL_getmetatable(state, "Vector4");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getCursorRegion(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                Control::State param1 = (Control::State)lua_enumFromString_ControlState(luaL_checkstring(state, 2));

                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)&(instance->getCursorRegion(param1));
                object->owns = false;
                luaL_getmetatable(state, "Rectangle");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getCursorUVs(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                Control::State param1 = (Control::State)lua_enumFromString_ControlState(luaL_checkstring(state, 2));

                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)&(instance->getCursorUVs(param1));
                object->owns = false;
                luaL_getmetatable(state, "ThemeUVs");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getFont(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)instance->getFont();
                object->owns = false;
                luaL_getmetatable(state, "Font");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                Control::State param1 = (Control::State)lua_enumFromString_ControlState(luaL_checkstring(state, 2));

                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)instance->getFont(param1);
                object->owns = false;
                luaL_getmetatable(state, "Font");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1 or 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getFontSize(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                unsigned int result = instance->getFontSize();

                // Push the return value onto the stack.
                lua_pushunsigned(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                Control::State param1 = (Control::State)lua_enumFromString_ControlState(luaL_checkstring(state, 2));

                Label* instance = getInstance(state);
                unsigned int result = instance->getFontSize(param1);

                // Push the return value onto the stack.
                lua_pushunsigned(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1 or 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getHeight(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                float result = instance->getHeight();

                // Push the return value onto the stack.
                lua_pushnumber(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getID(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                const char* result = instance->getID();

                // Push the return value onto the stack.
                lua_pushstring(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getImageColor(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING &&
                lua_type(state, 3) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                const char* param1 = luaL_checkstring(state, 2);

                // Get parameter 2 off the stack.
                Control::State param2 = (Control::State)lua_enumFromString_ControlState(luaL_checkstring(state, 3));

                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)&(instance->getImageColor(param1, param2));
                object->owns = false;
                luaL_getmetatable(state, "Vector4");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getImageRegion(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING &&
                lua_type(state, 3) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                const char* param1 = luaL_checkstring(state, 2);

                // Get parameter 2 off the stack.
                Control::State param2 = (Control::State)lua_enumFromString_ControlState(luaL_checkstring(state, 3));

                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)&(instance->getImageRegion(param1, param2));
                object->owns = false;
                luaL_getmetatable(state, "Rectangle");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getImageUVs(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING &&
                lua_type(state, 3) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                const char* param1 = luaL_checkstring(state, 2);

                // Get parameter 2 off the stack.
                Control::State param2 = (Control::State)lua_enumFromString_ControlState(luaL_checkstring(state, 3));

                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)&(instance->getImageUVs(param1, param2));
                object->owns = false;
                luaL_getmetatable(state, "ThemeUVs");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getMargin(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)&(instance->getMargin());
                object->owns = false;
                luaL_getmetatable(state, "ThemeSideRegions");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getOpacity(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                float result = instance->getOpacity();

                // Push the return value onto the stack.
                lua_pushnumber(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                Control::State param1 = (Control::State)lua_enumFromString_ControlState(luaL_checkstring(state, 2));

                Label* instance = getInstance(state);
                float result = instance->getOpacity(param1);

                // Push the return value onto the stack.
                lua_pushnumber(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1 or 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getPadding(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)&(instance->getPadding());
                object->owns = false;
                luaL_getmetatable(state, "ThemeSideRegions");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getRefCount(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                unsigned int result = instance->getRefCount();

                // Push the return value onto the stack.
                lua_pushunsigned(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getSkinColor(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)&(instance->getSkinColor());
                object->owns = false;
                luaL_getmetatable(state, "Vector4");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                Control::State param1 = (Control::State)lua_enumFromString_ControlState(luaL_checkstring(state, 2));

                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)&(instance->getSkinColor(param1));
                object->owns = false;
                luaL_getmetatable(state, "Vector4");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1 or 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getSkinRegion(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)&(instance->getSkinRegion());
                object->owns = false;
                luaL_getmetatable(state, "Rectangle");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                Control::State param1 = (Control::State)lua_enumFromString_ControlState(luaL_checkstring(state, 2));

                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)&(instance->getSkinRegion(param1));
                object->owns = false;
                luaL_getmetatable(state, "Rectangle");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1 or 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getState(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                Control::State result = instance->getState();

                // Push the return value onto the stack.
                lua_pushstring(state, lua_stringFromEnum_ControlState(result).c_str());

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getStyle(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)instance->getStyle();
                object->owns = false;
                luaL_getmetatable(state, "ThemeStyle");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getText(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                const char* result = instance->getText();

                // Push the return value onto the stack.
                lua_pushstring(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getTextAlignment(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                Font::Justify result = instance->getTextAlignment();

                // Push the return value onto the stack.
                lua_pushstring(state, lua_stringFromEnum_FontJustify(result).c_str());

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                Control::State param1 = (Control::State)lua_enumFromString_ControlState(luaL_checkstring(state, 2));

                Label* instance = getInstance(state);
                Font::Justify result = instance->getTextAlignment(param1);

                // Push the return value onto the stack.
                lua_pushstring(state, lua_stringFromEnum_FontJustify(result).c_str());

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1 or 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getTextColor(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)&(instance->getTextColor());
                object->owns = false;
                luaL_getmetatable(state, "Vector4");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                Control::State param1 = (Control::State)lua_enumFromString_ControlState(luaL_checkstring(state, 2));

                Label* instance = getInstance(state);
                ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                object->instance = (void*)&(instance->getTextColor(param1));
                object->owns = false;
                luaL_getmetatable(state, "Vector4");
                lua_setmetatable(state, -2);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1 or 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getTextRightToLeft(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                bool result = instance->getTextRightToLeft();

                // Push the return value onto the stack.
                lua_pushboolean(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                Control::State param1 = (Control::State)lua_enumFromString_ControlState(luaL_checkstring(state, 2));

                Label* instance = getInstance(state);
                bool result = instance->getTextRightToLeft(param1);

                // Push the return value onto the stack.
                lua_pushboolean(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1 or 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getWidth(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                float result = instance->getWidth();

                // Push the return value onto the stack.
                lua_pushnumber(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getX(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                float result = instance->getX();

                // Push the return value onto the stack.
                lua_pushnumber(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getY(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                float result = instance->getY();

                // Push the return value onto the stack.
                lua_pushnumber(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_getZIndex(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                int result = instance->getZIndex();

                // Push the return value onto the stack.
                lua_pushinteger(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_isEnabled(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                bool result = instance->isEnabled();

                // Push the return value onto the stack.
                lua_pushboolean(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_release(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA)
            {
                Label* instance = getInstance(state);
                instance->release();
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setAlignment(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                Control::Alignment param1 = (Control::Alignment)lua_enumFromString_ControlAlignment(luaL_checkstring(state, 2));

                Label* instance = getInstance(state);
                instance->setAlignment(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setAnimationPropertyValue(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TNUMBER &&
                lua_type(state, 3) == LUA_TUSERDATA)
            {
                // Get parameter 1 off the stack.
                int param1 = (int)luaL_checkint(state, 2);

                // Get parameter 2 off the stack.
                void* userdata3 = ScriptController::getInstance()->getObjectPointer(3, "AnimationValue");
                if (!userdata3)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'AnimationValue' for parameter 3.");
                    lua_error(state);
                }
                AnimationValue* param2 = (AnimationValue*)((ScriptController::LuaObject*)userdata3)->instance;

                Label* instance = getInstance(state);
                instance->setAnimationPropertyValue(param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 4:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TNUMBER &&
                lua_type(state, 3) == LUA_TUSERDATA &&
                lua_type(state, 4) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                int param1 = (int)luaL_checkint(state, 2);

                // Get parameter 2 off the stack.
                void* userdata3 = ScriptController::getInstance()->getObjectPointer(3, "AnimationValue");
                if (!userdata3)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'AnimationValue' for parameter 3.");
                    lua_error(state);
                }
                AnimationValue* param2 = (AnimationValue*)((ScriptController::LuaObject*)userdata3)->instance;

                // Get parameter 3 off the stack.
                float param3 = (float)luaL_checknumber(state, 4);

                Label* instance = getInstance(state);
                instance->setAnimationPropertyValue(param1, param2, param3);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 3 or 4).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setAutoHeight(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TBOOLEAN)
            {
                // Get parameter 1 off the stack.
                bool param1 = (luaL_checkint(state, 2) != 0);

                Label* instance = getInstance(state);
                instance->setAutoHeight(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setAutoWidth(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TBOOLEAN)
            {
                // Get parameter 1 off the stack.
                bool param1 = (luaL_checkint(state, 2) != 0);

                Label* instance = getInstance(state);
                instance->setAutoWidth(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setBorder(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 5:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TNUMBER &&
                lua_type(state, 3) == LUA_TNUMBER &&
                lua_type(state, 4) == LUA_TNUMBER &&
                lua_type(state, 5) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                float param1 = (float)luaL_checknumber(state, 2);

                // Get parameter 2 off the stack.
                float param2 = (float)luaL_checknumber(state, 3);

                // Get parameter 3 off the stack.
                float param3 = (float)luaL_checknumber(state, 4);

                // Get parameter 4 off the stack.
                float param4 = (float)luaL_checknumber(state, 5);

                Label* instance = getInstance(state);
                instance->setBorder(param1, param2, param3, param4);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 6:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TNUMBER &&
                lua_type(state, 3) == LUA_TNUMBER &&
                lua_type(state, 4) == LUA_TNUMBER &&
                lua_type(state, 5) == LUA_TNUMBER &&
                lua_type(state, 6) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                float param1 = (float)luaL_checknumber(state, 2);

                // Get parameter 2 off the stack.
                float param2 = (float)luaL_checknumber(state, 3);

                // Get parameter 3 off the stack.
                float param3 = (float)luaL_checknumber(state, 4);

                // Get parameter 4 off the stack.
                float param4 = (float)luaL_checknumber(state, 5);

                // Get parameter 5 off the stack.
                unsigned char param5 = (unsigned char)luaL_checkunsigned(state, 6);

                Label* instance = getInstance(state);
                instance->setBorder(param1, param2, param3, param4, param5);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 5 or 6).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setBounds(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TUSERDATA)
            {
                // Get parameter 1 off the stack.
                void* userdata2 = ScriptController::getInstance()->getObjectPointer(2, "Rectangle");
                if (!userdata2)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'Rectangle' for parameter 2.");
                    lua_error(state);
                }
                Rectangle* param1 = (Rectangle*)((ScriptController::LuaObject*)userdata2)->instance;

                Label* instance = getInstance(state);
                instance->setBounds(*param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setConsumeTouchEvents(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TBOOLEAN)
            {
                // Get parameter 1 off the stack.
                bool param1 = (luaL_checkint(state, 2) != 0);

                Label* instance = getInstance(state);
                instance->setConsumeTouchEvents(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setCursorColor(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TUSERDATA &&
                lua_type(state, 3) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                void* userdata2 = ScriptController::getInstance()->getObjectPointer(2, "Vector4");
                if (!userdata2)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'Vector4' for parameter 2.");
                    lua_error(state);
                }
                Vector4* param1 = (Vector4*)((ScriptController::LuaObject*)userdata2)->instance;

                // Get parameter 2 off the stack.
                unsigned char param2 = (unsigned char)luaL_checkunsigned(state, 3);

                Label* instance = getInstance(state);
                instance->setCursorColor(*param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setCursorRegion(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TUSERDATA &&
                lua_type(state, 3) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                void* userdata2 = ScriptController::getInstance()->getObjectPointer(2, "Rectangle");
                if (!userdata2)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'Rectangle' for parameter 2.");
                    lua_error(state);
                }
                Rectangle* param1 = (Rectangle*)((ScriptController::LuaObject*)userdata2)->instance;

                // Get parameter 2 off the stack.
                unsigned char param2 = (unsigned char)luaL_checkunsigned(state, 3);

                Label* instance = getInstance(state);
                instance->setCursorRegion(*param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setFont(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TUSERDATA)
            {
                // Get parameter 1 off the stack.
                void* userdata2 = ScriptController::getInstance()->getObjectPointer(2, "Font");
                if (!userdata2)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'Font' for parameter 2.");
                    lua_error(state);
                }
                Font* param1 = (Font*)((ScriptController::LuaObject*)userdata2)->instance;

                Label* instance = getInstance(state);
                instance->setFont(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TUSERDATA &&
                lua_type(state, 3) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                void* userdata2 = ScriptController::getInstance()->getObjectPointer(2, "Font");
                if (!userdata2)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'Font' for parameter 2.");
                    lua_error(state);
                }
                Font* param1 = (Font*)((ScriptController::LuaObject*)userdata2)->instance;

                // Get parameter 2 off the stack.
                unsigned char param2 = (unsigned char)luaL_checkunsigned(state, 3);

                Label* instance = getInstance(state);
                instance->setFont(param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2 or 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setFontSize(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                unsigned int param1 = (unsigned int)luaL_checkunsigned(state, 2);

                Label* instance = getInstance(state);
                instance->setFontSize(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TNUMBER &&
                lua_type(state, 3) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                unsigned int param1 = (unsigned int)luaL_checkunsigned(state, 2);

                // Get parameter 2 off the stack.
                unsigned char param2 = (unsigned char)luaL_checkunsigned(state, 3);

                Label* instance = getInstance(state);
                instance->setFontSize(param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2 or 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setImageColor(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING &&
                lua_type(state, 3) == LUA_TUSERDATA)
            {
                // Get parameter 1 off the stack.
                const char* param1 = luaL_checkstring(state, 2);

                // Get parameter 2 off the stack.
                void* userdata3 = ScriptController::getInstance()->getObjectPointer(3, "Vector4");
                if (!userdata3)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'Vector4' for parameter 3.");
                    lua_error(state);
                }
                Vector4* param2 = (Vector4*)((ScriptController::LuaObject*)userdata3)->instance;

                Label* instance = getInstance(state);
                instance->setImageColor(param1, *param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 4:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING &&
                lua_type(state, 3) == LUA_TUSERDATA &&
                lua_type(state, 4) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                const char* param1 = luaL_checkstring(state, 2);

                // Get parameter 2 off the stack.
                void* userdata3 = ScriptController::getInstance()->getObjectPointer(3, "Vector4");
                if (!userdata3)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'Vector4' for parameter 3.");
                    lua_error(state);
                }
                Vector4* param2 = (Vector4*)((ScriptController::LuaObject*)userdata3)->instance;

                // Get parameter 3 off the stack.
                unsigned char param3 = (unsigned char)luaL_checkunsigned(state, 4);

                Label* instance = getInstance(state);
                instance->setImageColor(param1, *param2, param3);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 3 or 4).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setImageRegion(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING &&
                lua_type(state, 3) == LUA_TUSERDATA)
            {
                // Get parameter 1 off the stack.
                const char* param1 = luaL_checkstring(state, 2);

                // Get parameter 2 off the stack.
                void* userdata3 = ScriptController::getInstance()->getObjectPointer(3, "Rectangle");
                if (!userdata3)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'Rectangle' for parameter 3.");
                    lua_error(state);
                }
                Rectangle* param2 = (Rectangle*)((ScriptController::LuaObject*)userdata3)->instance;

                Label* instance = getInstance(state);
                instance->setImageRegion(param1, *param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 4:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING &&
                lua_type(state, 3) == LUA_TUSERDATA &&
                lua_type(state, 4) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                const char* param1 = luaL_checkstring(state, 2);

                // Get parameter 2 off the stack.
                void* userdata3 = ScriptController::getInstance()->getObjectPointer(3, "Rectangle");
                if (!userdata3)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'Rectangle' for parameter 3.");
                    lua_error(state);
                }
                Rectangle* param2 = (Rectangle*)((ScriptController::LuaObject*)userdata3)->instance;

                // Get parameter 3 off the stack.
                unsigned char param3 = (unsigned char)luaL_checkunsigned(state, 4);

                Label* instance = getInstance(state);
                instance->setImageRegion(param1, *param2, param3);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 3 or 4).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setMargin(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 5:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TNUMBER &&
                lua_type(state, 3) == LUA_TNUMBER &&
                lua_type(state, 4) == LUA_TNUMBER &&
                lua_type(state, 5) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                float param1 = (float)luaL_checknumber(state, 2);

                // Get parameter 2 off the stack.
                float param2 = (float)luaL_checknumber(state, 3);

                // Get parameter 3 off the stack.
                float param3 = (float)luaL_checknumber(state, 4);

                // Get parameter 4 off the stack.
                float param4 = (float)luaL_checknumber(state, 5);

                Label* instance = getInstance(state);
                instance->setMargin(param1, param2, param3, param4);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 5).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setOpacity(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                float param1 = (float)luaL_checknumber(state, 2);

                Label* instance = getInstance(state);
                instance->setOpacity(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TNUMBER &&
                lua_type(state, 3) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                float param1 = (float)luaL_checknumber(state, 2);

                // Get parameter 2 off the stack.
                unsigned char param2 = (unsigned char)luaL_checkunsigned(state, 3);

                Label* instance = getInstance(state);
                instance->setOpacity(param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2 or 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setPadding(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 5:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TNUMBER &&
                lua_type(state, 3) == LUA_TNUMBER &&
                lua_type(state, 4) == LUA_TNUMBER &&
                lua_type(state, 5) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                float param1 = (float)luaL_checknumber(state, 2);

                // Get parameter 2 off the stack.
                float param2 = (float)luaL_checknumber(state, 3);

                // Get parameter 3 off the stack.
                float param3 = (float)luaL_checknumber(state, 4);

                // Get parameter 4 off the stack.
                float param4 = (float)luaL_checknumber(state, 5);

                Label* instance = getInstance(state);
                instance->setPadding(param1, param2, param3, param4);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 5).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setPosition(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TNUMBER &&
                lua_type(state, 3) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                float param1 = (float)luaL_checknumber(state, 2);

                // Get parameter 2 off the stack.
                float param2 = (float)luaL_checknumber(state, 3);

                Label* instance = getInstance(state);
                instance->setPosition(param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setSize(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TNUMBER &&
                lua_type(state, 3) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                float param1 = (float)luaL_checknumber(state, 2);

                // Get parameter 2 off the stack.
                float param2 = (float)luaL_checknumber(state, 3);

                Label* instance = getInstance(state);
                instance->setSize(param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setSkinColor(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TUSERDATA)
            {
                // Get parameter 1 off the stack.
                void* userdata2 = ScriptController::getInstance()->getObjectPointer(2, "Vector4");
                if (!userdata2)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'Vector4' for parameter 2.");
                    lua_error(state);
                }
                Vector4* param1 = (Vector4*)((ScriptController::LuaObject*)userdata2)->instance;

                Label* instance = getInstance(state);
                instance->setSkinColor(*param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TUSERDATA &&
                lua_type(state, 3) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                void* userdata2 = ScriptController::getInstance()->getObjectPointer(2, "Vector4");
                if (!userdata2)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'Vector4' for parameter 2.");
                    lua_error(state);
                }
                Vector4* param1 = (Vector4*)((ScriptController::LuaObject*)userdata2)->instance;

                // Get parameter 2 off the stack.
                unsigned char param2 = (unsigned char)luaL_checkunsigned(state, 3);

                Label* instance = getInstance(state);
                instance->setSkinColor(*param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2 or 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setSkinRegion(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TUSERDATA)
            {
                // Get parameter 1 off the stack.
                void* userdata2 = ScriptController::getInstance()->getObjectPointer(2, "Rectangle");
                if (!userdata2)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'Rectangle' for parameter 2.");
                    lua_error(state);
                }
                Rectangle* param1 = (Rectangle*)((ScriptController::LuaObject*)userdata2)->instance;

                Label* instance = getInstance(state);
                instance->setSkinRegion(*param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TUSERDATA &&
                lua_type(state, 3) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                void* userdata2 = ScriptController::getInstance()->getObjectPointer(2, "Rectangle");
                if (!userdata2)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'Rectangle' for parameter 2.");
                    lua_error(state);
                }
                Rectangle* param1 = (Rectangle*)((ScriptController::LuaObject*)userdata2)->instance;

                // Get parameter 2 off the stack.
                unsigned char param2 = (unsigned char)luaL_checkunsigned(state, 3);

                Label* instance = getInstance(state);
                instance->setSkinRegion(*param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2 or 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setState(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                Control::State param1 = (Control::State)lua_enumFromString_ControlState(luaL_checkstring(state, 2));

                Label* instance = getInstance(state);
                instance->setState(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setStyle(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TUSERDATA)
            {
                // Get parameter 1 off the stack.
                void* userdata2 = ScriptController::getInstance()->getObjectPointer(2, "ThemeStyle");
                if (!userdata2)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'Theme::Style' for parameter 2.");
                    lua_error(state);
                }
                Theme::Style* param1 = (Theme::Style*)((ScriptController::LuaObject*)userdata2)->instance;

                Label* instance = getInstance(state);
                instance->setStyle(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setText(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                const char* param1 = luaL_checkstring(state, 2);

                Label* instance = getInstance(state);
                instance->setText(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setTextAlignment(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING)
            {
                // Get parameter 1 off the stack.
                Font::Justify param1 = (Font::Justify)lua_enumFromString_FontJustify(luaL_checkstring(state, 2));

                Label* instance = getInstance(state);
                instance->setTextAlignment(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TSTRING &&
                lua_type(state, 3) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                Font::Justify param1 = (Font::Justify)lua_enumFromString_FontJustify(luaL_checkstring(state, 2));

                // Get parameter 2 off the stack.
                unsigned char param2 = (unsigned char)luaL_checkunsigned(state, 3);

                Label* instance = getInstance(state);
                instance->setTextAlignment(param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2 or 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setTextColor(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TUSERDATA)
            {
                // Get parameter 1 off the stack.
                void* userdata2 = ScriptController::getInstance()->getObjectPointer(2, "Vector4");
                if (!userdata2)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'Vector4' for parameter 2.");
                    lua_error(state);
                }
                Vector4* param1 = (Vector4*)((ScriptController::LuaObject*)userdata2)->instance;

                Label* instance = getInstance(state);
                instance->setTextColor(*param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TUSERDATA &&
                lua_type(state, 3) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                void* userdata2 = ScriptController::getInstance()->getObjectPointer(2, "Vector4");
                if (!userdata2)
                {
                    lua_pushstring(state, "Failed to retrieve a valid object pointer of type 'Vector4' for parameter 2.");
                    lua_error(state);
                }
                Vector4* param1 = (Vector4*)((ScriptController::LuaObject*)userdata2)->instance;

                // Get parameter 2 off the stack.
                unsigned char param2 = (unsigned char)luaL_checkunsigned(state, 3);

                Label* instance = getInstance(state);
                instance->setTextColor(*param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2 or 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setTextRightToLeft(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TBOOLEAN)
            {
                // Get parameter 1 off the stack.
                bool param1 = (luaL_checkint(state, 2) != 0);

                Label* instance = getInstance(state);
                instance->setTextRightToLeft(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 3:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TBOOLEAN &&
                lua_type(state, 3) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                bool param1 = (luaL_checkint(state, 2) != 0);

                // Get parameter 2 off the stack.
                unsigned char param2 = (unsigned char)luaL_checkunsigned(state, 3);

                Label* instance = getInstance(state);
                instance->setTextRightToLeft(param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2 or 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_setZIndex(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if (lua_type(state, 1) == LUA_TUSERDATA &&
                lua_type(state, 2) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                int param1 = (int)luaL_checkint(state, 2);

                Label* instance = getInstance(state);
                instance->setZIndex(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_Label_static_ANIMATE_OPACITY(lua_State* state)
{
    // Validate the number of parameters.
    if (lua_gettop(state) > 0)
    {
        lua_pushstring(state, "Invalid number of parameters (expected 0).");
        lua_error(state);
    }

    int result = Label::ANIMATE_OPACITY;

    // Push the return value onto the stack.
    lua_pushinteger(state, result);

    return 1;
}

int lua_Label_static_ANIMATE_POSITION(lua_State* state)
{
    // Validate the number of parameters.
    if (lua_gettop(state) > 0)
    {
        lua_pushstring(state, "Invalid number of parameters (expected 0).");
        lua_error(state);
    }

    int result = Label::ANIMATE_POSITION;

    // Push the return value onto the stack.
    lua_pushinteger(state, result);

    return 1;
}

int lua_Label_static_ANIMATE_POSITION_X(lua_State* state)
{
    // Validate the number of parameters.
    if (lua_gettop(state) > 0)
    {
        lua_pushstring(state, "Invalid number of parameters (expected 0).");
        lua_error(state);
    }

    int result = Label::ANIMATE_POSITION_X;

    // Push the return value onto the stack.
    lua_pushinteger(state, result);

    return 1;
}

int lua_Label_static_ANIMATE_POSITION_Y(lua_State* state)
{
    // Validate the number of parameters.
    if (lua_gettop(state) > 0)
    {
        lua_pushstring(state, "Invalid number of parameters (expected 0).");
        lua_error(state);
    }

    int result = Label::ANIMATE_POSITION_Y;

    // Push the return value onto the stack.
    lua_pushinteger(state, result);

    return 1;
}

int lua_Label_static_ANIMATE_SIZE(lua_State* state)
{
    // Validate the number of parameters.
    if (lua_gettop(state) > 0)
    {
        lua_pushstring(state, "Invalid number of parameters (expected 0).");
        lua_error(state);
    }

    int result = Label::ANIMATE_SIZE;

    // Push the return value onto the stack.
    lua_pushinteger(state, result);

    return 1;
}

int lua_Label_static_ANIMATE_SIZE_HEIGHT(lua_State* state)
{
    // Validate the number of parameters.
    if (lua_gettop(state) > 0)
    {
        lua_pushstring(state, "Invalid number of parameters (expected 0).");
        lua_error(state);
    }

    int result = Label::ANIMATE_SIZE_HEIGHT;

    // Push the return value onto the stack.
    lua_pushinteger(state, result);

    return 1;
}

int lua_Label_static_ANIMATE_SIZE_WIDTH(lua_State* state)
{
    // Validate the number of parameters.
    if (lua_gettop(state) > 0)
    {
        lua_pushstring(state, "Invalid number of parameters (expected 0).");
        lua_error(state);
    }

    int result = Label::ANIMATE_SIZE_WIDTH;

    // Push the return value onto the stack.
    lua_pushinteger(state, result);

    return 1;
}

}
