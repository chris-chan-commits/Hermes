#include "Camera.h"

#include <glm/gtx/projection.hpp>
#include <glm/common.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace beye
{
	Ref<Camera> Camera::CreateOrthographicCamera(float left, float right, float bottom, float top)
	{
		Ref<Camera> camera = CreateRef<Camera>();
		camera->projection = glm::ortho(left, right, bottom, top);
		camera->view = glm::mat4(1.0f);

		return camera;
	}
	Ref<Camera> Camera::CreatePerspectiveCamera(float fov, float width, float height, float near, float far)
	{
		Ref<Camera> camera = CreateRef<Camera>();
		camera->projection = glm::perspective(fov, height / width, near, far);
		camera->view = glm::mat4(1.0f);

		return camera;
	}
}