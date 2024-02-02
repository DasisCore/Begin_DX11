
struct VS_INPUT
{
	float4 position : POSITION;
	float4 color : COLOR;
};

struct VS_OUTPUT
{
	float4 position : SV_POSITION;	//SYSTEM VALUE
	float4 color : COLOR;
};



// IA -> VS -> RS -> PS ->OM
VS_OUTPUT VS(VS_INPUT input)	// 위치와 관련
{
	VS_OUTPUT output;

	output.position = input.position;
	output.color = input.color;

	return output;
}

float4 PS(VS_OUTPUT input) : SV_Target	// 색상과 관련
{
	


	return input.color;
}