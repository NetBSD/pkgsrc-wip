# $NetBSD: Makefile,v 1.1.1.1 2004/04/28 15:41:51 airhead Exp $
#

DISTNAME=	latex2rtf-1.9.15
CATEGORIES=	print wip
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=latex2rtf/}

MAINTAINER=	airhead@users.sourceforge.net
HOMEPAGE=	http://latex2rtf.sourceforge.net/
COMMENT=	Filter that converts LaTeX into RTF (MS's Rich Text Format)

NO_CONFIGURE=	yes
USE_BUILDLINK3=	yes

INSTALL_TARGET= install install-info

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
