# $NetBSD: Makefile,v 1.1.1.1 2010/07/17 20:29:17 gschwarz Exp $

DISTNAME=	dmt-ux-0.178
CATEGORIES=	comms
MASTER_SITES=	http://www.spida.net/projects/software/dmt-ux/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.spida.net/projects/software/dmt-ux/index.de.html
COMMENT=	DSL modem tool for Unix
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	YES
MAKE_ENV+=	LIBS=${LIBS:Q}

INSTALLATION_DIRS=	bin

post-extract:
		cd ${WRKSRC} && ${LN} -s modules/speedtouch.o speedtouch.o

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/dmt-ux ${DESTDIR}${PREFIX}/bin

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../databases/rrdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
