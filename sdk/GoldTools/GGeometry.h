#pragma once

#include "arxHeaders.h"
#include <list>
using std::list;

#ifndef  GOLD_EXPORT
#define  GOLD_EXPORT
#endif 


/*!
 @brief ������صķ���
 */
namespace GGeometry
{
    /*!
     @brief ��ȡ����յı任����
     @param
     @return
     */
    AcGeMatrix3d GOLD_EXPORT GetBlockMatrix3d(AcDbBlockReference* pRef,
                                  AcDbBlockTableRecord* pRec);
	AcGeMatrix3d GOLD_EXPORT GetBlockMatrix3d(AcDbBlockReference* pRef);

    /*!
     @brief
     @param
     @return
     */
    AcGePoint3d GOLD_EXPORT Mid(AcGePoint3d& pnt1, AcGePoint3d& pnt2);

    /*!
     @brief �ж��Ƿ��ཻ
     @param
     @return
     */
    bool GOLD_EXPORT IsIntersect(AcDbExtents& ext1, AcDbExtents& ext2);

	/*!
	 @brief �ж�ext1�Ƿ����ext2���������߽磩
	 */
	bool GOLD_EXPORT IsIn(AcDbExtents* ext1,AcDbExtents* ext2);
	bool GOLD_EXPORT IsIn(AcDbExtents ext1, AcDbExtents ext2);
	/*!
	@brief �ж�ext1�Ƿ����ext2�������߽磩
	*/
	bool GOLD_EXPORT IsInclude(AcDbExtents ext1, AcDbExtents ext2);

	//�ж�ext1 �Ƿ�� ext2���
	bool GOLD_EXPORT isSameExtents(AcDbExtents* ext1, AcDbExtents* ext2);
	bool GOLD_EXPORT isSameExtents(AcDbExtents ext1, AcDbExtents ext2);

	//�Ƿ����
	bool GOLD_EXPORT isAdjoin(AcDbExtents* ext1, AcDbExtents* ext2);
	bool GOLD_EXPORT isAdjoin(AcDbExtents ext1, AcDbExtents ext2);

	//compareExtent�Ƿ���ext ���ҡ��ϡ��½���
	bool GOLD_EXPORT isLeftAdjoin(AcDbExtents ext, AcDbExtents compareExtent);
	bool GOLD_EXPORT isRightAdjoin(AcDbExtents ext, AcDbExtents compareExtent);
	bool GOLD_EXPORT isTopAdjoin(AcDbExtents ext, AcDbExtents compareExtent);
	bool GOLD_EXPORT isBottomAdjoin(AcDbExtents ext, AcDbExtents compareExtent);

	/*!
	@brief �ж�point���Ƿ���ext�ķ�Χ��
	*/
	bool GOLD_EXPORT IsPointInExtents(const AcGePoint3d& point , const AcDbExtents& ext);

	enum IntersectionType {NoIntersection = 0x0001 ,			//���ཻ��
											LeftIntersection = 0x0002 ,			//�ཻ����߽�
											RightIntersection = 0x0004,		//�ཻ���ұ߽�
											TopIntersection = 0x0008,			//�ཻ���ϱ߽�
											BottomIntersection = 0x0010,	//�ཻ���±߽�
											HorInContainment = 0x0020,		//ˮƽ�������������ڰ�����ϵ
											HorOutContainment = 0x0040,	//ˮƽ�������������������ϵ
											VerInContainment = 0x0080,		//��ֱ�������������ڰ�����ϵ
											VerOutContainment = 0x0100};	//��ֱ�������������������ϵ
	typedef unsigned long IntersectionTypes;

	/*!
	@brief �ж�ext1�����ext2�����ڵ�λ�ã�����ֵ����IntersectionType��һ������ , offsetX��offsetYΪ�������ֵ , Ϊ��ֵʱ���ʵ�����ext2�ķ�Χ�������С��
	*/
	IntersectionTypes GOLD_EXPORT TwoExtentsIntersection(const AcDbExtents& ext1, const AcDbExtents& ext2 , double offsetX = 0.0 , double offsetY = 0.0);


	//���������
	void GOLD_EXPORT InverseMatrix(AcGeMatrix3d &matrix);

	//�������λ��������������ʵ���б�(�������ң���������)
	std::list<AcDbEntity *> GOLD_EXPORT SortEntitiesByOrientation(const std::list<AcDbEntity *> &allEntities);
}