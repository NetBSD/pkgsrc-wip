# $NetBSD$

DISTNAME=	IraVoice-0.7.2
PKGNAME=	iravoice-0.7.2
CATEGORIES=	misc
MASTER_SITES=	https://iravoice.com/downloads/
EXTRACT_SUFX=	.dmg

MAINTAINER=	hello@iravoice.com
HOMEPAGE=	https://iravoice.com/
COMMENT=	Private on-device dictation app for Apple-silicon Macs
LICENSE=	iravoice-license-20260724

# PAD line 96 permits software catalogs to mirror the original notarized DMG,
# but forbids repackaging, bundling, or modification. That allows distfile
# mirroring while still prohibiting redistribution of the pkgsrc binary package.
LICENSE_FILE=		${FILESDIR}/iravoice-license-20260724
RESTRICTED=		PAD permits mirroring only the unmodified official DMG
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

NO_BUILD=		yes
NO_CONFIGURE=		yes
EXTRACT_ONLY=		# empty
INSTALL_UNSTRIPPED=	yes

# LSMinimumSystemVersion is 26.0, which corresponds to Darwin 25.
NOT_FOR_PLATFORM=	Darwin-[0-9].*-aarch64 Darwin-1[0-9].*-aarch64 Darwin-2[0-4].*-aarch64
ONLY_FOR_PLATFORM=	Darwin-*-aarch64

USE_LANGUAGES=		# none
USE_TOOLS+=		pax

INSTALLATION_DIRS+=	Applications
CHECK_SHLIBS_SKIP+=	Applications/IraVoice.app/Contents/MacOS/IraVoice

do-install:
	${SH} ${FILESDIR}/install-dmg.sh \
		${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${DESTDIR}${PREFIX}/Applications \
		${WRKDIR}

.include "../../mk/bsd.pkg.mk"
