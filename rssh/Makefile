# $NetBSD: Makefile,v 1.3 2005/11/02 18:00:26 thomasklausner Exp $
#

DISTNAME=		rssh-2.1.1
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rssh/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.pizzashack.org/rssh/
COMMENT=		Restricted shell allowing only scp and/or sftp

GNU_CONFIGURE=		yes

# TODO THIS MUST BE PORTED TO BSD!!!! f*cking wordexp.? !!!
ONLY_FOR_PLATFORM=	Linux-*-* Irix-*-* Solaris-*-* AIX-*-*

.include "../../mk/bsd.pkg.mk"
