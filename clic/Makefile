# $NetBSD: Makefile,v 1.2 2018/02/28 16:32:56 leot Exp $

DISTNAME=	clic-v1.01
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	net
MASTER_SITES=	ftp://bitreich.org/releases/clic/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	gopher://bitreich.org/1/scm/clic
COMMENT=	Common LISP terminal based gopher client written
LICENSE=	2-clause-bsd

MAKE_FLAGS+=	PREFIX="${PREFIX}"
MAKE_FLAGS+=	MANDIR="${PREFIX}/${PKGMANDIR}"

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/ecl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
