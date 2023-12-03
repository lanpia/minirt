/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:37:53 by soohkang          #+#    #+#             */
/*   Updated: 2023/12/01 17:38:12 by soohkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

typedef struct s_vector {
	double x, y, z;
}              t_vector;

// 벡터 덧셈
t_vector vector_add(t_vector a, t_vector b) {
	return (t_vector){a.x + b.x, a.y + b.y, a.z + b.z};
}

// 벡터 뺄셈
t_vector vector_sub(t_vector a, t_vector b) {
	return (t_vector){a.x - b.x, a.y - b.y, a.z - b.z};
}

// 벡터 정규화
t_vector vector_normalize(t_vector v) {
	double len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (t_vector){v.x / len, v.y / len, v.z / len};
}

// 벡터 내적
double vector_dot(t_vector a, t_vector b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

// 확산 반사 계산
double compute_diffuse(t_vector light_dir, t_vector normal) {
	double intensity = vector_dot(vector_normalize(light_dir), normal);
	return fmax(intensity, 0.0); // 음수가 되지 않도록 최소값을 0으로 설정
}

// ...

// 메인 함수 예시
int main() {
	t_vector light_dir = {1.0, -1.0, 0.0}; // 광원 방향
	t_vector surface_normal = {0.0, 0.0, 1.0}; // 표면의 법선 벡터
	double diffuse = compute_diffuse(light_dir, surface_normal);
	
	printf("Diffuse intensity: %f\n", diffuse);
	return 0;
}
