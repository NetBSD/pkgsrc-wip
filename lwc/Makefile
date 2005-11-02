# $NetBSD: Makefile,v 1.5 2005/11/02 18:00:21 thomasklausner Exp $
#

DISTNAME=		lwc-1.3.2
CATEGORIES=		lang
MASTER_SITES=		http://students.ceid.upatras.gr/~sxanth/lwc/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://students.ceid.upatras.gr/~sxanth/lwc/
COMMENT=		Lightweight C++


BUILD_TARGET= objdir/lwc
SUBST_CLASSES=gcc
SUBST_STAGE.gcc=pre-build
SUBST_FILES.gcc=Makefile
SUBST_SED.gcc= -e 's,CCC\ \=,\#,g' -e 's,CC\ =\ ,CC+=-c ${CFLAGS}\#,' \
	-e 's,$$(CCC),${CC},g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/objdir/lwc ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
