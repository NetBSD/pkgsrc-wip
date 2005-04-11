# $NetBSD: Makefile,v 1.4 2005/04/11 21:13:57 tvierling Exp $
#

DISTNAME=		lwc-1.3.2
CATEGORIES=		wip lang
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
