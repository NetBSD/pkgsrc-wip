# $NetBSD: Makefile,v 1.1.1.1 2004/02/26 23:48:37 poppnk Exp $
#

DISTNAME=		rssh-2.1.1
CATEGORIES=		wip shells
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rssh/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.pizzashack.org/rssh/
COMMENT=		Restricted shell allowing only scp and/or sftp

USE_BUILDLINK3=         yes
GNU_CONFIGURE=		yes

# TODO THIS MUST BE PORTED TO BSD!!!! f*cking wordexp.? !!!
ONLY_FOR_PLATFORM=	Linux-*-* Irix-*-* Solaris-*-* AIX-*-*

.include "../../mk/bsd.pkg.mk"
