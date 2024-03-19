# $NetBSD: Makefile,v 1.3 2023/07/08 20:14:16 pin Exp $

DISTNAME=	iamb-0.0.9
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=ulyssa/}
GITHUB_TAG=	b41faff9b7678e093c9260c7610c887731692b9b

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://iamb.chat/
COMMENT=	Matrix client for Vim addicts
LICENSE=	apache-2.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
