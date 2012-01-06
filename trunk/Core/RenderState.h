/********************************************************************
	创建时间:	6:1:2012   14:48
	文件名: 	f:\Aurorar\Core\RenderState.h
	创建者:		丁亮
	
	文件作用:	渲染状态
*********************************************************************/
#pragma once

namespace Aurora
{
	enum ShadeOptions
	{
		SO_FLAT,
		SO_GOURAUD,
		SO_PHONG
	};

	enum FogMode
	{
		FOG_NONE,
		FOG_EXP,
		FOG_EXP2,
		FOG_LINEAR
	};

	enum CullingMode
	{
		CULL_NONE = 1,
		CULL_CLOCKWISE = 2,
		CULL_ANTICLOCKWISE = 3
	};

	enum PolygonMode
	{
		PM_POINTS = 1,
		PM_WIREFRAME = 2,
		PM_SOLID = 3
	};

	enum CompareFunction
	{
		CMPF_ALWAYS_FAIL,
		CMPF_ALWAYS_PASS,
		CMPF_LESS,
		CMPF_LESS_EQUAL,
		CMPF_EQUAL,
		CMPF_NOT_EQUAL,
		CMPF_GREATER_EQUAL,
		CMPF_GREATER
	};

	enum StencilOperation
	{
		SOP_KEEP,
		SOP_ZERO,
		SOP_REPLACE,
		SOP_INCREMENT,
		SOP_DECREMENT,
		SOP_INCREMENT_WRAP,
		SOP_DECREMENT_WRAP,
		SOP_INVERT
	};

	struct RenderState
	{
		ShadeOptions			sahde_options;
		FogMode					fog_mode;
		CullingMode				culling_mode;
		PolygonMode				polygon_mode;
		CompareFunction			compare_func;
		StencilOperation		stencil_opt;	
	};


}