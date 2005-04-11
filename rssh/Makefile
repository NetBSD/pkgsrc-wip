# $NetBSD: Makefile,v 1.2 2005/04/11 21:15:30 tvierling Exp $
#

DISTNAME=		rssh-2.1.1
CATEGORIES=		wip shells
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rssh/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.pizzashack.org/rssh/
COMMENT=		Restricted shell allowing only scp and/or sftp

GNU_CONFIGURE=		yes

# TODO THIS MUST BE PORTED TO BSD!!!! f*cking wordexp.? !!!
ONLY_FOR_PLATFORM=	Linux-*-* Irix-*-* Solaris-*-* AIX-*-*

.include "../../mk/bsd.pkg.mk"
