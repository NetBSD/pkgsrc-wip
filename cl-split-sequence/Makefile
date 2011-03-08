# $NetBSD: Makefile,v 1.2 2011/03/08 13:36:33 ddeus Exp $
#

VERSION=        20011114.1
SHORTNAME=	split-sequence
DISTNAME=	${SHORTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://ftp.linux.org.uk/pub/lisp/experimental/cclan/

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://www.cliki.net/SPLIT-SEQUENCE
COMMENT=        Common Lisp utility to split sequences
LICENSE=        public-domain

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}/${DISTNAME}

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
