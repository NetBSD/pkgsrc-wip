# $NetBSD: Makefile,v 1.1.1.1 2005/05/06 21:27:03 gregschenzel Exp $

DISTNAME=       mxterm
PKGNAME=        mxterm-128
CATEGORIES=     wip
MASTER_SITES=	http://programming.ccp14.ac.uk/ftp-mirror/programming/cygwin/pub/cygwin/xfree/contrib/
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=     inittab@netizenweb.com
HOMEPAGE=	http://www.fh-wilhelmshaven.de/~akcaagaa/index_mxterm.html
COMMENT=        Motif XTerm

GNU_CONFIGURE=  YES
USE_X11=	YES

PERMIT_PACKAGE_CDROM=   Yes
PERMIT_PACKAGE_FTP=     Yes
PERMIT_DISTFILES_CDROM= Yes
PERMIT_DISTFILES_FTP=   Yes

.include "../../mk/bsd.prefs.mk"

pre-configure:
	@(cd ${WRKSRC}; \
	make clean || ${TRUE}; \
	[ -f config.cache ] && ${RM} config.cache)

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

