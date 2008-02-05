# $NetBSD: Makefile,v 1.1 2008/02/05 15:51:48 koifren Exp $

DISTNAME=	mono-addins-0.3
CATEGORIES=	devel
MASTER_SITES=	http://www.go-mono.com/sources/mono-addins/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/Mono.Addins
COMMENT=	Framework for creating extensible applications

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../wip/mono/buildlink3.mk"
.include "../../x11/gtk2-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
