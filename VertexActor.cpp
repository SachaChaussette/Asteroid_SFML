#include "VertexActor.h"
#include "CameraManager.h"

using namespace Camera;

VertexActor::VertexActor(const u_int& _count, const PrimitiveType& _type, const string& _name) : Actor(_name)
{
	vertex = CreateComponent<VertexComponent>(_count, _type);
	renderMeshToken = -1;
}

VertexActor::VertexActor(const VertexActor& _other) : Actor(_other)
{
	vertex = CreateComponent<VertexComponent>(_other.vertex);
	renderMeshToken = _other.renderMeshToken;
}

void VertexActor::Construct()
{
	Super::Construct();

	const RenderData& _data = RenderData(bind(&VertexActor::RenderVertices, this, _1));
	renderMeshToken = M_CAMERA.BindOnRenderWindow(_data);
}

void VertexActor::Deconstruct()
{
	Super::Deconstruct();
	M_CAMERA.UnbindOnRenderWindow(renderMeshToken);
}


void VertexActor::RenderVertices(RenderWindow& _window)
{
	_window.draw(*vertex->GetVertex()->GetDrawable());
}