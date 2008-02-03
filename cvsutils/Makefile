# $NetBSD: Makefile,v 1.6 2008/02/03 14:11:16 tnn2 Exp $
#

DISTNAME=		cvsutils-0.2.3
CATEGORIES=		devel
MASTER_SITES=		http://www.red-bean.com/cvsutils/releases/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.red-bean.com/cvsutils/releases/
COMMENT=		CVS utilities to facilitate working

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl:run

REPLACE_PERL=		cvsu.pl cvsdo.pl cvschroot.pl
REPLACE_SH=		cvsco.sh cvsdiscard.sh cvspurge.sh cvstrim.sh

.include "../../mk/bsd.pkg.mk"
