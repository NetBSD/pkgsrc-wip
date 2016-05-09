# $NetBSD$

KAPPSVER?=	16.04.0
CATEGORIES+=	kde
MASTER_SITES=	${MASTER_SITE_KDE:=applications/${KAPPSVER}/src/}
EXTRACT_SUFX=	.tar.xz

.include "../../wip/kde5/Makefile.common"
