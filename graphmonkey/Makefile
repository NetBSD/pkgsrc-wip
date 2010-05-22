# $NetBSD: Makefile,v 1.1.1.1 2010/05/22 23:09:14 jihbed Exp $
#

DISTNAME=	GraphMonkey-1.7
PKGNAME=	${DISTNAME:S/GraphMonkey/graphmonkey/}
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/graphmonkey/GraphMonkey/GraphMonkey-1.7/

MAINTAINER=	ppkgsrc-users@NetBSD.org
HOMEPAGE=	http://graphmonkey.sourceforge.net/
COMMENT=	GTK\#-based graphing calculator
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

NO_BUILD= yes

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_DATA}  ${WRKSRC}/GraphMonkey.exe ${DESTDIR}${PREFIX}/bin
.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
