# $NetBSD: Makefile,v 1.5 2006/12/18 06:43:33 dhowland Exp $
#

DISTNAME=		cvsutils-0.2.3
CATEGORIES=		devel
MASTER_SITES=		http://www.red-bean.com/cvsutils/releases/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.red-bean.com/cvsutils/releases/
COMMENT=		CVS utilities to facilitate working

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

REPLACE_PERL=		cvsu.pl cvsdo.pl cvschroot.pl
REPLACE_SH=		cvsco.sh cvsdiscard.sh cvspurge.sh cvstrim.sh

.include "../../mk/bsd.pkg.mk"
