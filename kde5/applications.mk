# $NetBSD$

KAPPSVER?=	17.12.1
CATEGORIES+=	kde
MASTER_SITES=	${MASTER_SITE_KDE:=applications/${KAPPSVER}/src/}
EXTRACT_SUFX=	.tar.xz

.include "../../wip/kde5/Makefile.common"
