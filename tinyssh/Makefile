# $NetBSD$

DISTNAME=		${GITHUB_PROJECT}
PKGNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=janmojzis/}
GITHUB_PROJECT=		tinyssh
GITHUB_TAG=		20260601

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://tinyssh.org/
COMMENT=		Minimalistic SSHv2 server
LICENSE=		cc0-1.0-universal

DEPENDS+=		ucspi-tcp>=0.88:../../net/ucspi-tcp

.include "../../mk/bsd.pkg.mk"
