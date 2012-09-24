# $NetBSD: Makefile,v 1.3 2012/09/24 18:26:54 asau Exp $
#

DISTNAME=	clips-6.24
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clipsrules/}
EXTRACT_SUFX=	.tar.Z
DISTFILES=	clips_core_source_624.tar.Z make_and_help_files_624.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://clipsrules.sourceforge.net/
COMMENT=	Tool for Building Expert Systems
LICENSE=	public-domain

USE_LANGUAGES=	c

WRKSRC=		${WRKDIR}/clipssrc/clipssrc

MAKE_FILE=	makefile.gcc
BUILD_TARGET=	clips

INSTALLATION_DIRS=	bin share/doc/clips

post-extract:
	${RUN} cd ${WRKDIR}; mv makefile.* ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clips ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/clips.hlp ${DESTDIR}${PREFIX}/share/doc/clips

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
