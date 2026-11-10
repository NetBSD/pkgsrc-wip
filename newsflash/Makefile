# $NetBSD$

DISTNAME=	newsflash-6.0.2
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_GITLAB:=api/v4/projects/8320003/packages/generic/newsflash/6.0.2/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	gourd753+netbsd@xenos5.net
HOMEPAGE=	https://gitlab.com/api/v4/projects/8320003/packages/generic/newsflash/6.0.2/ # TODO: check
COMMENT=	RSS Reader to follow your favorite blogs & news sites
#LICENSE=	gnu-gpl-v3

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

# https://gitlab.com/news-flash/html2gtk.git#558ac604
# remove libc from default = ["libc", "pdf-export", "smart-thumbnails"]
# in src/meson.build

PKGCONFIG_OVERRIDE+=	vendor/aws-lc-sys/aws-lc/pkgconfig/libcrypto.pc.in
PKGCONFIG_OVERRIDE+=	vendor/aws-lc-sys/aws-lc/pkgconfig/libssl.pc.in
PKGCONFIG_OVERRIDE+=	vendor/aws-lc-sys/aws-lc/pkgconfig/product.pc.in

.include "cargo-depends.mk"

.include "../../devel/meson/build.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
