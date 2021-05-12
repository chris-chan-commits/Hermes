#include "Camera.h"

#include <glm/gtx/projection.hpp>
#include <glm/common.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace beye
{
	void Camera::Translate(const glm::vec3& translation)
	{
		view = glm::translate(view, translation);
	}
	Ref<Camera> Camera::CreateOrthographicCamera(float left, float right, float bottom, float top)
	{
		Ref<Camera> camera = CreateRef<Camera>();
		camera->projection = glm::ortho(left, right, bottom, top);
		camera->view = glm::mat4(1.0f);

		return camera;
	}
	Ref<Camera> Camera::CreatePerspectiveCamera(float fov, float aspect, float near, float far)
	{
		Ref<Camera> camera = CreateRef<Camera>();
		camera->projection = glm::perspective(fov, aspect, near, far);
		camera->view = glm::mat4(1.0f);

		return camera;
	}
}