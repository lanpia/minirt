/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 03:28:03 by nahyulee          #+#    #+#             */
/*   Updated: 2023/11/04 03:28:19 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 3차원 벡터의 덧셈
t_vctr3 addVector(t_vctr3 a, t_vctr3 b) {
    t_vctr3 result = {a.x + b.x, a.y + b.y, a.z + b.z};
    return result;
}

// 3차원 벡터의 뺄셈
t_vctr3 subtractVector(t_vctr3 a, t_vctr3 b) {
    t_vctr3 result = {a.x - b.x, a.y - b.y, a.z - b.z};
    return result;
}

// 3차원 벡터의 스칼라 곱셈
t_vctr3 multiplyVector(t_vctr3 v, float scalar) {
    t_vctr3 result = {v.x * scalar, v.y * scalar, v.z * scalar};
    return result;
}

// 3차원 벡터의 스칼라 나눗셈
t_vctr3 divideVector(t_vctr3 v, float scalar) {
    // 스칼라가 0이 아닌지 확인하고, 0이면 오류 메시지를 출력
    if (scalar == 0) {
        printf("Error: Division by zero.\n");
        return v; // 이 경우, 변하지 않은 벡터 반환
    }
    t_vctr3 result = {v.x / scalar, v.y / scalar, v.z / scalar};
    return result;
}