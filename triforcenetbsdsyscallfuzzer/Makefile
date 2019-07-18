# $NetBSD$

DISTNAME=	TriforceNetBSDSyscallFuzzer-0.0.${SNAPSHOT}
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=akulpillai/}
GITHUB_TAG=	8318e3f598d4cbc99356402aafa4b7194b0ef2c6

SNAPSHOT=	2019.07.19

MAINTAINER=	vishnu@akulpillai.com
HOMEPAGE=	https://github.com/akulpillai/TriforceNetBSDSyscallFuzzer/
COMMENT=	NetBSD syscall fuzzing with TriforceAFL
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND mit AND modified-bsd
LICENSE+=	AND apache-2.0

WRKSRC=		${WRKDIR}/TriforceNetBSDSyscallFuzzer-${GITHUB_TAG}

PYTHON_VERSIONS_ACCEPTED=	27

AFLPREFIX=	${PREFIX}/${PKGBASE}

MAKE_FLAGS=	PREFIX=${AFLPREFIX}

.include "../../wip/triforceafl/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
