# $NetBSD: Makefile,v 1.7 2008/09/09 02:46:43 bsadewitz Exp $
#

DISTNAME=		cvsutils-0.2.5
CATEGORIES=		devel
MASTER_SITES=		http://www.red-bean.com/cvsutils/releases/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.red-bean.com/cvsutils/releases/
COMMENT=		CVS utilities to facilitate working

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl:run

REPLACE_PERL=		*.pl
REPLACE_SH=		*.sh

.include "../../mk/bsd.pkg.mk"
