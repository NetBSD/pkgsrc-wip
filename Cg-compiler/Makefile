# $NetBSD: Makefile,v 1.7 2012/09/27 11:19:04 othyro Exp $
#

DISTNAME=	Cg-3.1_April2012_x86${DIST_ARCH}
PKGNAME=	${DISTNAME:S/-/-compiler-/:S/_April2012_x86${DIST_ARCH}//}
CATEGORIES=	lang
MASTER_SITES=	http://developer.download.nvidia.com/cg/Cg_3.1/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://developer.nvidia.com/cg-toolkit
COMMENT=	Compiler for the Cg 3.1 language
LICENSE=	nvidia-license

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c c++

EMUL_PLATFORMS=		linux-i386 linux-x86_64
EMUL_MODULES.linux=	base
EMUL_REQD=		suse>=7.3

BUILD_DIRS=		# empty
RUN_LDCONFIG=		yes
USE_TOOLS+=		pax

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=		PLIST.common
.if ${EMUL_ARCH} == "i386"
  DIST_ARCH=		# blank
  INSTALLATION_DIRS=	${EMULDIR}/lib
  PLIST_SRC+=		PLIST.linux-i386
.elif ${EMUL_ARCH} == "x86_64"
  DIST_ARCH=		_64
  INSTALLATION_DIRS=	${EMULDIR}/lib64
  PLIST_SRC+=		PLIST.linux-x86_64
.else
  DIST_ARCH=		# blank
  INSTALLATION_DIRS=	${EMULDIR}/lib
  PLIST_SRC+=		PLIST.linux-i386
.endif

INSTALLATION_DIRS+=	bin include/Cg share/doc/Cg-compiler \
			share/doc/html/Cg-compiler \
			share/examples/Cg-compiler/Direct3D10/advanced/cgfx_buffer_lighting \
			share/examples/Cg-compiler/Direct3D10/advanced/combine_programs \
			share/examples/Cg-compiler/Direct3D10/advanced/custom_state_assignments \
			share/examples/Cg-compiler/Direct3D10/advanced/gs_shrinky \
			share/examples/Cg-compiler/Direct3D10/advanced/gs_simple \
			share/exmaples/Cg-compiler/Direct3D10/advanced/include_string \
			share/examples/Cg-compiler/Direct3D10/advanced/interpolation_modifier \
			share/examples/Cg-compiler/Direct3D10/basic/02_vertex_and_fragment_program \
			share/examples/Cg-compiler/Direct3D10/basic/03_uniform_parameter \
			share/examples/Cg-compiler/Direct3D10/basic/04_varying_parameter \
			share/examples/Cg-compiler/Direct3D10/basic/05_texture_sampling \
			share/examples/Cg-compiler/Direct3D10/basic/06_vertex_twisting \
			share/examples/Cg-compiler/Direct3D10/basic/07_two_texture_accesses \
			share/examples/Cg-compiler/Direct3D10/basic/cgfx_buffer \
			share/examples/Cg-compiler/Direct3D10/basic/cgfx_simple \
			share/examples/Cg-compiler/Direct3D10/basic/cgfx_texture \
			share/examples/Cg-compiler/Direct3D10/miniDXUT \
			share/examples/Cg-compiler/Direct3D11/advanced/cgfx_buffer_lighting \
			share/examples/Cg-compiler/Direct3D11/advanced/cgfx_bumpdemo_array \
			share/examples/Cg-compiler/Direct3D11/advanced/cgfx_bumpdemo \
			share/examples/Cg-compiler/Direct3D11/advanced/cgfx_latest \
			share/examples/Cg-compiler/Direct3D11/advanced/combine_programs \
			share/examples/Cg-compiler/Direct3D11/advanced/custom_state_assignments \
			share/examples/Cg-compiler/Direct3D11/advanced/gs_shrinky \
			share/examples/Cg-compiler/Direct3D11/advanced/gs_simple \
			share/examples/Cg-compiler/Direct3D11/advanced/include_string \
			share/examples/Cg-compiler/Direct3D11/advanced/interpolation_modifier \
			share/examples/Cg-compiler/Direct3D11/basic/02_vertex_and_fragment_program \
                        share/examples/Cg-compiler/Direct3D11/basic/03_uniform_parameter \
                        share/examples/Cg-compiler/Direct3D11/basic/04_varying_parameter \
                        share/examples/Cg-compiler/Direct3D11/basic/05_texture_sampling \
                        share/examples/Cg-compiler/Direct3D11/basic/06_vertex_twisting \
                        share/examples/Cg-compiler/Direct3D11/basic/07_two_texture_accesses \
                        share/examples/Cg-compiler/Direct3D11/basic/cgfx_buffer \
                        share/examples/Cg-compiler/Direct3D11/basic/cgfx_simple \
                        share/examples/Cg-compiler/Direct3D11/basic/cgfx_texture \
			share/examples/Cg-compiler/Direct3D9/advanced/cgfx_buffer_lighting \
                        share/examples/Cg-compiler/Direct3D9/advanced/cgfx_bumpdemo \
			share/examples/Cg-compiler/Direct3D9/basic/01_vertex_program \
			share/examples/Cg-compiler/Direct3D9/basic/02_vertex_and_fragment_program \
                        share/examples/Cg-compiler/Direct3D9/basic/03_uniform_parameter \
                        share/examples/Cg-compiler/Direct3D9/basic/04_varying_parameter \
                        share/examples/Cg-compiler/Direct3D9/basic/05_texture_sampling \
                        share/examples/Cg-compiler/Direct3D9/basic/06_vertex_twisting \
                        share/examples/Cg-compiler/Direct3D9/basic/07_two_texture_accesses \
			share/examples/Cg-compiler/Direct3D9/miniDXUT \
			share/examples/Cg-compiler/OpenGL/advanced/cgfx_boxfilter \
			share/examples/Cg-compiler/OpenGL/advanced/cgfx_bumpdemo_array \
			share/examples/Cg-compiler/OpenGL/advanced/cgfx_bumpdemo \
			share/examples/Cg-compiler/OpenGL/advanced/cgfx_interfaces \
			share/examples/Cg-compiler/OpenGL/advanced/cgfx_latest \
			share/examples/Cg-compiler/OpenGL/advanced/cgfx_procfx \
			share/examples/Cg-compiler/OpenGL/advanced/cgfx_texture_array \
			share/examples/Cg-compiler/OpenGL/advanced/combine_program \
			share/examples/Cg-compiler/OpenGL/advanced/custom_state_assignments \
			share/examples/Cg-compiler/OpenGL/advanced/generic_attribs \
			share/examples/Cg-compiler/OpenGL/advanced/gs_interp_quad \
			share/examples/Cg-compiler/OpenGL/advanced/gs_md2render \
			share/examples/Cg-compiler/OpenGL/advanced/gs_quadnormal \
			share/examples/Cg-compiler/OpenGL/advanced/gs_shrinky \
			share/examples/Cg-compiler/OpenGL/advanced/gs_simple \
			share/examples/Cg-compiler/OpenGL/advanced/include_string \
			share/examples/Cg-compiler/OpenGL/advanced/interpolation_modifier \
			share/examples/Cg-compiler/OpenGL/advanced/texture_array \
			share/examples/Cg-compiler/OpenGL/advanced/vertex_texture \
			share/examples/Cg-compiler/OpenGL/basic/01_vertex_program \
			share/examples/Cg-compiler/OpenGL/basic/02_vertex_and_fragment_program \
			share/examples/Cg-compiler/OpenGL/basic/03_uniform_parameter \
			share/examples/Cg-compiler/OpenGL/basic/04_varying_parameter \
			share/examples/Cg-compiler/OpenGL/basic/05_texture_sampling \
			share/examples/Cg-compiler/OpenGL/basic/06_vertex_twisting \
			share/examples/Cg-compiler/OpenGL/basic/07_two_texture_accesses \
			share/examples/Cg-compiler/OpenGL/basic/08_vertex_transform \
			share/examples/Cg-compiler/OpenGL/basic/09_vertex_lighting \
			share/examples/Cg-compiler/OpenGL/basic/10_fragment_lighting \
			share/examples/Cg-compiler/OpenGL/basic/11_two_lights_with_structs \
			share/examples/Cg-compiler/OpenGL/basic/12_light_attenuation \
			share/examples/Cg-compiler/OpenGL/basic/13_spotlight \
			share/examples/Cg-compiler/OpenGL/basic/14_bulge \
			share/examples/Cg-compiler/OpenGL/basic/15_particle_system \
			share/examples/Cg-compiler/OpenGL/basic/16_keyframe_interpolation \
			share/examples/Cg-compiler/OpenGL/basic/18_cube_map_reflection \
			share/examples/Cg-compiler/OpenGL/basic/19_cube_map_refraction \
			share/examples/Cg-compiler/OpenGL/basic/20_chromatic_dispersion \
			share/examples/Cg-compiler/OpenGL/basic/21_bump_map_wall \
			share/examples/Cg-compiler/OpenGL/basic/22_specular_bump_map \
			share/examples/Cg-compiler/OpenGL/basic/23_bump_map_floor \
			share/examples/Cg-compiler/OpenGL/basic/24_bump_map_torus \
			share/examples/Cg-compiler/OpenGL/basic/25_uniform_fog \
			share/examples/Cg-compiler/OpenGL/basic/26_toon_shading \
			share/examples/Cg-compiler/OpenGL/basic/27_projective_texturing \
			share/examples/Cg-compiler/OpenGL/buffers/buffer_lighting \
			share/examples/Cg-compiler/OpenGL/buffers/cgfx_buffer_lighting \
			share/examples/Cg-compiler/OpenGL/buffers/ubo_lighting \
			share/examples/Cg-compiler/OpenGL/glew/include/GL \
			share/examples/Cg-compiler/OpenGL/glew/src \
			share/examples/Cg-compiler/OpenGL/tessellation/cgfx_tessellation \
			share/examples/Cg-compiler/OpenGL/tessellation/phong_tess \
			share/examples/Cg-compiler/OpenGL/tessellation/pn_triangles \
			share/examples/Cg-compiler/OpenGL/tessellation/quad_tri_bezier \
			share/examples/Cg-compiler/OpenGL/tessellation/terrain_tess \
			share/examples/Cg-compiler/OpenGL/tessellation/tess_bezier \
			share/examples/Cg-compiler/OpenGL/tessellation/tess_simple \
			share/examples/Cg-compiler/Tools/cgfxcat \
			share/examples/Cg-compiler/Tools/cginfo \
			share/examples/Cg-compiler/Trace

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usr/bin/* ${DESTDIR}${PREFIX}/bin
.if ${EMUL_ARCH} == "i386"
	${INSTALL_DATA} ${WRKSRC}/usr/lib/* ${DESTDIR}${EMULDIR}/lib
.elif ${EMUL_ARCH} == "x86_64"
	${INSTALL_DATA} ${WRKSRC}/usr/lib64/* ${DESTDIR}${EMULDIR}/lib64
.else
	${INSTALL_DATA} ${WRKSRC}/usr/lib/* ${DESTDIR}${EMULDIR}/lib
.endif
	${INSTALL_DATA} ${WRKSRC}/usr/include/Cg/* \
		${DESTDIR}${PREFIX}/include/Cg
	${INSTALL_DATA} ${WRKSRC}/usr/local/Cg/README ${DESTDIR}${PREFIX}/share/doc/Cg-compiler
	${INSTALL_DATA} ${WRKSRC}/usr/local/Cg/docs/Cg* ${DESTDIR}${PREFIX}/share/doc/Cg-compiler
	${INSTALL_DATA} ${WRKSRC}/usr/local/Cg/docs/html/* ${DESTDIR}${PREFIX}/share/doc/html/Cg-compiler
	cd ${WRKSRC}/usr/local/Cg/examples && pax -rw Direct3D* OpenGL README T* ${DESTDIR}${PREFIX}/share/examples/Cg-compiler

.include "../../mk/bsd.pkg.mk"
