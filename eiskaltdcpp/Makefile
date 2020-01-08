# $NetBSD$

DISTNAME=	eiskaltdcpp-2.2.10
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=eiskaltdcpp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eiskaltdcpp/eiskaltdcpp/
COMMENT=	Cross-platform program that uses the Direct Connect and ADC protocols
LICENSE=	gnu-gpl-v3

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		perl:run

CMAKE_ARGS+=		-DUSE_QT=OFF
CMAKE_ARGS+=		-DUSE_QT5=ON

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/xmlrpc-c/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"

# optional:
#liblua5.1 (optional, see cmake keys)
#miniupnpc (optional, see cmake keys)
# gtk interface:
#gettext
#libpango
#libgtk2 (>= 2.24)
#libglib2 (>= 2.24)
#libnotify (>= 0.4.1) (optional, see cmake keys)
#libgnome2 (optional, see cmake keys)
#libcanberra-gtk3-0 (optional, see cmake keys)
# perl modules needed:
#    Getopt::Long  (libgetopt-long-descriptive-perl)
#    Data::Dump    (libdata-dump-perl)
#    Term::ShellUI (libterm-shellui-perl)
#    RPC::XML      (librpc-xml-perl)  (optional, see cmake keys)
#    JSON::RPC     (libjson-rpc-perl) (optional, see cmake keys)

.include "../../mk/bsd.pkg.mk"
