#include "MeshActor.h"
#include "CameraManager.h"


using namespace Camera;

MeshActor::MeshActor(const float _radius, const string& _path, const TextureExtensionType& _textureType,
	const IntRect& _rect, bool _isRepeated, bool _isSmooth, const size_t& _pointCount, 
	const string& _name) : Actor(_name)
{
	visibility = ActorMesh::Visible;
	mesh = CreateComponent<MeshComponent>(_radius, _path, _textureType, _rect, _isRepeated, _isSmooth, _pointCount);
	renderMeshToken = -1;
}

MeshActor::MeshActor(const Vector2f& _size, const string& _path, const TextureExtensionType& _textureType,
	const IntRect& _rect, bool _isRepeated, bool _isSmooth, const string& _name) : Actor(_name)
{
	visibility = ActorMesh::Visible;
	mesh = CreateComponent<MeshComponent>(_size, _path, _textureType, _rect, _isRepeated, _isSmooth);
	renderMeshToken = -1;
}

MeshActor::MeshActor(const RectangleShapeData& _data, const string& _name) : Actor(_name)
{
	visibility = ActorMesh::Visible;
	mesh = CreateComponent<MeshComponent>(_data);
	renderMeshToken = -1;
}
MeshActor::MeshActor(const vector<Vector2f>& _point, const string& _path, const TextureExtensionType& _textureType,
	const IntRect& _rect, bool _isRepeated, bool _isSmooth,const string& _name) : Actor(_name)
{
	visibility = ActorMesh::Visible;
	mesh = CreateComponent<MeshComponent>(_point, _path, _textureType, _rect, _isRepeated, _isSmooth);
	renderMeshToken = -1;
}

MeshActor::MeshActor(const MeshActor& _other) : Actor(_other)
{
	visibility = _other.visibility;
	mesh = CreateComponent<MeshComponent>(_other.mesh);
	renderMeshToken = _other.renderMeshToken;
}

void MeshActor::Construct()
{
	Super::Construct();
	const RenderData& _data = RenderData(bind(&MeshActor::RenderMesh, this, placeholders::_1));
	renderMeshToken = M_CAMERA.BindOnRenderWindow(_data);
}

void MeshActor::Deconstruct()
{
	Super::Deconstruct();
	M_CAMERA.UnbindOnRenderWindow(renderMeshToken);
}

void MeshActor::RenderMesh(RenderWindow& _window)
{
	if(!(visibility & ActorMesh::Hidden)) return
	_window.draw(*mesh->GetShape()->GetDrawable());
}