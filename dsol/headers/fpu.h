/*!\file
 * \brief ���� ���� �������� ���������, ������� � �������, ����������� ��� �������������� � ���������� ������ FPU.
 *
 * Copyright(C) ��� �������� �������, 2018
 * Copyright(C) ������� ������������� ��� �������� �������
 * ��� ����� ��������.
 *
 * ����������� �����������, ��������� � ���� �����, ������������� ������ ��� 
 * ���������������� �����, � ������������� ������������� ���������� � ��������� 
 * ����������� "�������� �������". ��� ����������� ����������� ������������ "��� ����" 
 * ��� �����-���� ��������, "�������� �������" ������������ �� ����� ��������, 
 * ����������� ��� ���������������, ������� ��� ��������������� �������� �������� �����������, 
 * ����������� ��� ���������� ���� � ���������� ���� ���������������� �������������. 
 * ����������� "�������� �������" �� ����� ������� ��������������� �� ������������� 
 * ������������ �����������, �� ������������� �������� ��� ���� �� ������, ��������� �����, 
 * ��� ����� ������ ����� ���������������� �������������, �� �����-���� ��������. 
 * ����������� "�������� �������" ��������� �� ����� ����� ������� ��������� � ����������� 
 * ����������� ��� �����������. ����������� "�������� �������" ����� �� ���� ������� 
 * ��������� ��� ��������, ��� ��� ����������� ���������� �������� ��� ������������� 
 * ��� ����������� ������������ ��� �����������.
 *
 * ���������� �� �������������, �����������, ��������� � ��������������� ����� ������������ 
 * ����������� � ������������ ��������������� �������� �������� "�������� �������" � 
 * ��������������� ��������� ���� ����� �������� ��� ������, ��� �������, 
 * ��� ��� ����������� ����������� ������������ ��������� � ������������������ �����������
 * "�������� �������". ��� ����� ������ ���������������� �� ���� ������ ����� ����.
 */

#ifndef FPU_H_
#define FPU_H_

#include "types.h"
#include <stdio.h>
#include <math.h> 

/**
 * @brief ��������� ��� ������� � ��������� FPU
 */
typedef struct
{
    __RW uint32_t ADD_SUB;                                                      /**< ��������: 0x0000 ����� ������ ��������/��������� */
    __RW float    ADD_A;                                                        /**< ��������: 0x0004 ������� � ��� �������� ��������/��������� */
    __RW float    ADD_B;                                                        /**< ��������: 0x0008 ������� � ��� �������� ��������/���������  */
    __RW float    MUL_A;                                                        /**< ��������: 0x000C ������ ��������� ��� �������� ��������� */
    __RW float    MUL_B;                                                        /**< ��������: 0x0010 ������ ��������� ��� �������� ���������  */
    __WO uint32_t CONTROL;                                                      /**< ��������: 0x0014 ������� ���������� */
    __RO float    ADD_OUT;                                                      /**< ��������: 0x0018 ��������� �������� ��������  */
    __RO float    MUL_OUT;	                                                /**< ��������: 0x001C ��������� �������� ��������� */
}FPU_T;

/**
 * @brief ������� � ���� ��� �������� ADD_SUB
 */
#define FPU_ADD_SUB_SUB_EN      ((uint32_t)(0 << 0))                            /**< ��������� ������ �������� */
#define FPU_ADD_SUB_ADD_EN      ((uint32_t)(1 << 0))                            /**< ��������� ������ ��������� */

/**
 * @brief ������� � ���� ��� �������� CONTROL
 */
#define FPU_CONTROL_ADD_EN      ((uint32_t)(1 << 0))                            /**< ������ �������� �������� */
#define FPU_CONTROL_MUL_EN      ((uint32_t)(1 << 1))                            /**< ������ �������� ��������� */

/**
 * @brief ����� ����� FPU.
 * @retval None.
 */
void FPU_DeInit(void);

/**
 * @brief ������������� ����� FPU.
 * @retval None.
 */
void FPU_Init(void);

/**
 * @brief �������� ���� ����� ��� ������ ����� FPU
 * @param A: ��������� 1
 * @param B: ��������� 2
 * @retval �����
 */
float FPU_ADD(float A, float B);

/**
 * @brief ��������� ���� ����� ��� ������ ����� FPU
 * @param A: �����������
 * @param B: ����������
 * @retval �������
 */
float FPU_SUB(float A, float B);

/**
 * @brief ��������� ���� ����� ��� ������ ����� FPU
 * @param A: ��������� 1
 * @param B: ��������� 2
 * @retval ������������
 */
float FPU_MUL(float A, float B);

/**
 * @brief ���������
 */ 
static int factorial (int n)
{
  return (n < 2) ? 1 : n * factorial (n - 1);
}

/**
 * @brief ���������� ������
 *
 * ��� ����������� �������� ��������� ������ �������� �������������� ��� ����������� �������� ����������, ��� � �������� ����� FPU
 * @param A: �������� � ��������
 * @retval �����
 */
float FPU_SIN(float A);
   
/**
 * @brief ���������� ���������
 *
 * ��� ����������� �������� ��������� ������ �������� �������������� ��� ����������� �������� ����������, ��� � �������� ����� FPU
 * @param A: �������� � ��������
 * @retval ��������
 */
float FPU_ASIN(float A);
   
/**
 * @brief ���������� �����������
 *
 * ��� ����������� �������� ��������� ������ �������� �������������� ��� ����������� �������� ����������, ��� � �������� ����� FPU
 * @param A: �������� � ��������
 * @retval �����������
 */
float FPU_ACOS(float A);

/**
 * @brief ���������� ��������
 *
 * ��� ����������� �������� ��������� ������ �������� �������������� ��� ����������� �������� ����������, ��� � �������� ����� FPU
 * @param A: �������� � ��������
 * @retval �������
 */
float FPU_COS(float A);

/**
 * @brief ���������� ����������� ����� ��� ������ ����� FPU
 * @param A: �����
 * ��� ����������� �������� ��������� ������ �������� �������������� ��� ����������� �������� ����������, ��� � �������� ����� FPU
 * @retval ���������� ������ �� A 
 */
float FPU_sqrt(float A);

/**
 * @brief ���������� � ������� ��� ������ ����� FPU
 * @param A: �����
 * @retval ������� �� A 
 */
float FPU_pow2(float A);

/**
 * @brief ���������� � ��� ��� ������ ����� FPU
 * @param A: �����
 * @retval ��� �� A 
 */
float FPU_pow3(float A);

/**
 * @brief ���������� ��������
 *
 * ��� ����������� �������� ��������� ������ �������� �������������� ��� ����������� �������� ����������, ��� � �������� ����� FPU
 * @param A: �������� � ��������
 * @retval �������
 */
float FPU_tg(float A);

/**
 * @brief ���������� �����������
 *
 * ��� ����������� �������� ��������� ������ �������� �������������� ��� ����������� �������� ����������, ��� � �������� ����� FPU
 * @param A: �������� � ��������
 * @retval ����������
 */
float FPU_atg(float A);
   


#endif /* FPU_H */