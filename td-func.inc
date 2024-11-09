/*
    SA:MP TextDraw Funcitons | Lasho4 (Jax Teller)
    (C) 2024
*/

#if defined _tdfunc_included
	#endinput
#endif
#define _tdfunc_included

#tryinclude <a_samp>

// Preview models
static
        g_TextDraw_PreviewModel[MAX_TEXT_DRAWS],
        p_TextDraw_PreviewModel[MAX_PLAYERS][MAX_PLAYER_TEXT_DRAWS];

// Stocks
stock tdf_TextDrawSetPreviewModel(Text:textdraw, model)
{
    g_TextDraw_PreviewModel[_:textdraw] = model;
    return TextDrawSetPreviewModel(textdraw, model);
}
#if defined _ALS_TextDrawSetPreviewModel
	#undef TextDrawSetPreviewModel
#else
	#define _ALS_TextDrawSetPreviewModel
#endif
#define TextDrawSetPreviewModel tdf_TextDrawSetPreviewModel

stock tdf_PlayerTextDrawSetPreviewMod(playerid, PlayerText:textdraw, model)
{
    p_TextDraw_PreviewModel[playerid][_:textdraw] = model;
    return PlayerTextDrawSetPreviewModel(playerid, textdraw, model);
}
#if defined _ALS_PlayerTextDrawSetPreviewMo
	#undef PlayerTextDrawSetPreviewModel
#else
	#define _ALS_PlayerTextDrawSetPreviewMo
#endif
#define PlayerTextDrawSetPreviewModel tdf_PlayerTextDrawSetPreviewMod

// * Functions
stock TextDrawGetPreviewModel(Text:textdraw)
{
    if(!(0 <= _:textdraw < MAX_TEXT_DRAWS))
        return 0;
    return g_TextDraw_PreviewModel[_:textdraw];
}
stock PlayerTextDrawGetPreviewModel(playerid, PlayerText:textdraw)
{
    if(!(0 <= playerid < MAX_PLAYERS))
        return 0;
    if(!(0 <= _:textdraw < MAX_PLAYER_TEXT_DRAWS))
        return 0;
    return p_TextDraw_PreviewModel[playerid][_:textdraw];
}