# $NetBSD: Makefile,v 1.4 2007/06/02 03:34:42 hoka_adam Exp $

PKGNAME=	dfuibe_installer-1.1.7
CATEGORIES=	sysutils

.include "../../wip/bsdinstaller/bsdinstaller.mk"

WRKSRC=		${WRKDIR}/${DISTNAME}/installer/src/backend/installer

HOMEPAGE=       http://www.bsdinstaller.com/
MAINTAINER=	adam.hoka@gmail.com
COMMENT=	DFUI BSD Installer backend

SHAREDIR=	${PREFIX}/share/dfuibe_installer

do-install:
	${INSTALL_PROGRAM} -o root -g wheel -m 555 ${WRKSRC}/dfuibe_installer ${PREFIX}/sbin
	${MKDIR} -p ${SHAREDIR}
	${INSTALL_DATA} -o root -g wheel -m 555 ${WRKSRC}/conf/cmdnames.conf ${SHAREDIR}

.include "../../wip/libinstaller/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
