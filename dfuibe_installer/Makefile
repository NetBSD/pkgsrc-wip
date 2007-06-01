# $NetBSD: Makefile,v 1.3 2007/06/01 20:07:31 hoka_adam Exp $

DISTNAME=	bsdinstaller-20070528
PKGNAME=	dfuibe_installer-1.1.7
CATEGORIES=	sysutils

MASTER_SITES=	http://rnrdoctor.sytes.net/~replaced/bsdinstaller/
WRKSRC=		${WRKDIR}/${DISTNAME}/installer/src/backend/installer

HOMEPAGE=       http://www.bsdinstaller.com/
MAINTAINER=	adam.hoka@gmail.com
COMMENT=	DFUI BSD Installer backend

FILESDIR=	${.CURDIR}/../../wip/bsdinstaller/files
SHAREDIR=	${PREFIX}/share/dfuibe_installer

pre-configure:
	${CP} ${FILESDIR}/Config ${WRKDIR}/${DISTNAME}/installer/src/Config

do-install:
	${INSTALL_PROGRAM} -o root -g wheel -m 555 ${WRKSRC}/dfuibe_installer ${PREFIX}/sbin
	${MKDIR} -p ${SHAREDIR}
	${INSTALL_DATA} -o root -g wheel -m 555 ${WRKSRC}/conf/cmdnames.conf ${SHAREDIR}

.include "../../wip/libinstaller/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
