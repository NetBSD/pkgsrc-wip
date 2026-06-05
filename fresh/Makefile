# $NetBSD$

DISTNAME=	fresh-editor-0.3.12-source
PKGNAME=	fresh-0.3.12  # This creates a simpler package name 'fresh'
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=sinelaw/}
GITHUB_PROJECT=	fresh
# GITHUB_TAG=	v${PKGVERSION_NOREV}  # This will use v0.3.12
GITHUB_RELEASE=	v0.3.12

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://getfresh.dev/
COMMENT=	Terminal-based IDE and text editor with zero configuration
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/fresh-0.3.12
USE_LANGUAGES=	c c++
USE_TOOLS+=	pax

CARGO_WRKSRC=	${WRKSRC}
CARGO_INSTALL_ARGS=	install --path crates/fresh-editor --root ${DESTDIR}${PREFIX} ${DEFAULT_CARGO_ARGS}

DISTFILES=	${DEFAULT_DISTFILES} ratatui-wgpu-cdcf5c6.tar.gz
SITES.ratatui-wgpu-cdcf5c6.tar.gz= \
		-${MASTER_SITE_GITHUB:=Jesterhearts/}ratatui-wgpu/archive/cdcf5c6.tar.gz

post-extract:
	${MKDIR} ${WRKDIR}/vendor/ratatui-wgpu-0.4.1
	cd ${WRKDIR} && \
		/usr/bin/tar -xzf ${_DISTDIR}/ratatui-wgpu-cdcf5c6.tar.gz \
		--strip-components=1 \
		-C ${WRKDIR}/vendor/ratatui-wgpu-0.4.1
	${RUN} cd ${WRKDIR}/vendor/ratatui-wgpu-0.4.1 && \
		printf '{"package":null,"files":{}}' > .cargo-checksum.json
	${RUN} printf '\n[source."git+https://github.com/Jesterhearts/ratatui-wgpu?rev=cdcf5c6#cdcf5c6987adba56b060f6a8532ee83b25a4e3e5"]\ngit = "https://github.com/Jesterhearts/ratatui-wgpu"\nrev = "cdcf5c6"\nreplace-with = "vendored-sources"\n' \
		>> ${WRKDIR}/.cargo/config.toml


.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
