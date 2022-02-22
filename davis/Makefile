# $NetBSD$

DISTNAME=	davis-0.1.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=SimonPersson/}
GITHUB_PROJECT=	davis
GITHUB_TAG=	f16a22288e6cac4b62ba8cc25cba06c6ae4a89ab

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SimonPersson/davis/
COMMENT=	CLI client for MPD
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/davis \
		 ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/davis.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/davis.1
	${INSTALL_SCRIPT} ${WRKSRC}/subcommands/cover/davis-cover \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/subcommands/cur/davis-cur-horizontal \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/subcommands/cur/davis-cur-vertical \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/subcommands/fzf/davis-fzf \
		${DESTDIR}${PREFIX}/bin

DEPENDS+=	picat-[0-9]*:../../graphics/picat
DEPENDS+=	fzf-[0-9]*:../../sysutils/fzf
#DEPENDS+=       musicpd-[0-9]*:../../audio/musicpd

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
