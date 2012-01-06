/********************************************************************
	创建时间:	6:1:2012   17:29
	文件名: 	f:\Aurorar\Core\BlendMode.h
	创建者:		丁亮
	
	文件作用:	混合模式
*********************************************************************/
#pragma once

namespace Aurora 
{

	// 纹理混合

// 	HRESULT SetTextureStageState(
// 		[in]  DWORD Stage,
// 		[in]  D3DTEXTURESTAGESTATETYPE Type,
// 		[in]  DWORD Value
// 		);

	// Type 纹理混合操作类型
    enum LayerBlendType
    {
        LBT_COLOUR,
        LBT_ALPHA
    };

	// Value 纹理混合参数
	enum LayerBlendSource
	{
		LBS_CURRENT,
		LBS_TEXTURE,
		LBS_DIFFUSE,
		LBS_SPECULAR,
		LBS_MANUAL
	};

	// Value 纹理混合具体操作
    enum LayerBlendOperation 
	{
        /// use source1 without modification
        LBX_SOURCE1,
        /// use source2 without modification
        LBX_SOURCE2,
        /// multiply source1 and source2 together
        LBX_MODULATE,
        /// as LBX_MODULATE but brighten afterwards (x2)
        LBX_MODULATE_X2,
        /// as LBX_MODULATE but brighten more afterwards (x4)
        LBX_MODULATE_X4,
        /// add source1 and source2 together
        LBX_ADD,
        /// as LBX_ADD, but subtract 0.5 from the result
        LBX_ADD_SIGNED,
        /// as LBX_ADD, but subtract product from the sum
        LBX_ADD_SMOOTH,
        /// subtract source2 from source1
        LBX_SUBTRACT,
        /// use interpolated alpha value from vertices to scale source1, then add source2 scaled by (1-alpha)
        LBX_BLEND_DIFFUSE_ALPHA,
        /// as LBX_BLEND_DIFFUSE_ALPHA, but use alpha from texture
        LBX_BLEND_TEXTURE_ALPHA,
        /// as LBX_BLEND_DIFFUSE_ALPHA, but use current alpha from previous stages
        LBX_BLEND_CURRENT_ALPHA,
        /// as LBX_BLEND_DIFFUSE_ALPHA but use a constant manual blend value (0.0-1.0)
        LBX_BLEND_MANUAL,
        /// dot product of color1 and color2 
        LBX_DOTPRODUCT,
        /// use interpolated color values from vertices to scale source1, then add source2 scaled by (1-color)
        LBX_BLEND_DIFFUSE_COLOUR
    };


	// 场景混合(两个Pass之间的混合方式)

    enum SceneBlendType
    {
        /// Make the object transparent based on the final alpha values in the texture
        SBT_TRANSPARENT_ALPHA,
        /// Make the object transparent based on the colour values in the texture (brighter = more opaque)
        SBT_TRANSPARENT_COLOUR,
        /// Add the texture values to the existing scene content
        SBT_ADD,
		/// Multiply the 2 colours together
		SBT_MODULATE,
        /// The default blend mode where source replaces destination
        SBT_REPLACE
    };

    enum SceneBlendFactor
    {
        SBF_ONE,
        SBF_ZERO,
        SBF_DEST_COLOUR,
        SBF_SOURCE_COLOUR,
        SBF_ONE_MINUS_DEST_COLOUR,
        SBF_ONE_MINUS_SOURCE_COLOUR,
        SBF_DEST_ALPHA,
        SBF_SOURCE_ALPHA,
        SBF_ONE_MINUS_DEST_ALPHA,
        SBF_ONE_MINUS_SOURCE_ALPHA

    };

	enum SceneBlendOperation
	{
		SBO_ADD,
		SBO_SUBTRACT,
		SBO_REVERSE_SUBTRACT,
		SBO_MIN,
		SBO_MAX
	};


}
