# $NetBSD: Makefile,v 1.2 2005/05/07 08:29:06 gregschenzel Exp $

DISTNAME=	mxterm
PKGNAME=	mxterm-129
CATEGORIES=	wip
MASTER_SITES=	http://programming.ccp14.ac.uk/ftp-mirror/programming/cygwin/pub/cygwin/xfree/contrib/
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=	inittab@netizenweb.com
HOMEPAGE=	http://www.fh-wilhelmshaven.de/~akcaagaa/index_mxterm.html
COMMENT=	Motif XTerm

GNU_CONFIGURE=	YES
USE_X11=	YES

DIST_SUBDIR=	${PKGNAME_NOREV}

pre-configure:
	@(cd ${WRKSRC}; \
	make clean || ${TRUE}; \
	[ -f config.cache ] && ${RM} config.cache)

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

