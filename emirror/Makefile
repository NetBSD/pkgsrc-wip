# $NetBSD: Makefile,v 1.1.1.1 2003/04/18 19:22:22 hweiss Exp $
#

DISTNAME=	emirror-2.1.21
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=emirror/} \
		ftp://ftp.fu-berlin.de/unix/network/emirror/ \
		ftp://eclipt.uni-klu.ac.at/pub/projects/emirror/

MAINTAINER=	holger@zedat.fu-berlin.de
HOMEPAGE=	http://eclipt.uni-klu.ac.at/emirror.php
COMMENT=	FTP mirroring tool with nice HTML logfiles

GNU_CONFIGURE=	yes
NO_BUILD=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} \
			--with-python=${PYTHONBIN}

post-extract:
		${MV} ${WRKSRC}/man/emirror.1 ${WRKSRC}/man/emirror.1.in

post-configure:
		${SED} -e "s|@PREFIX@|${PREFIX}|g" \
			-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g" \
			< ${WRKSRC}/man/emirror.1.in > ${WRKSRC}/man/emirror.1

.include	"../../lang/python/application.mk"
.include	"../../mk/bsd.pkg.mk"
