# $NetBSD$

PLASMAVER?=	5.11.5
CATEGORIES+=	kde
MASTER_SITES=	${MASTER_SITE_KDE:=plasma/${PLASMAVER}/}
EXTRACT_SUFX=	.tar.xz

EXTRACT_USING=	gtar

.include "../../wip/kde5/Makefile.common"
