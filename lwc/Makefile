# $NetBSD: Makefile,v 1.7 2012/10/03 09:04:32 asau Exp $
#

DISTNAME=		lwc-1.3.2
CATEGORIES=		lang
MASTER_SITES=		http://students.ceid.upatras.gr/~sxanth/lwc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://students.ceid.upatras.gr/~sxanth/lwc/
COMMENT=		Lightweight C++


BUILD_TARGET= objdir/lwc
SUBST_CLASSES+=gcc
SUBST_STAGE.gcc=pre-build
SUBST_FILES.gcc=Makefile
SUBST_SED.gcc= -e 's,CCC\ \=,\#,g' -e 's,CC\ =\ ,CC+=-c ${CFLAGS}\#,' \
	-e 's,$$(CCC),${CC},g'

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/objdir/lwc ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
