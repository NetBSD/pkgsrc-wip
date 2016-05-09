# $NetBSD$

PLASMAVER?=	5.6.3
CATEGORIES+=	kde
MASTER_SITES=	${MASTER_SITE_KDE:=plasma/${PLASMAVER}/}
EXTRACT_SUFX=	.tar.xz

.include "../../wip/kde5/Makefile.common"
