/* Autogenerated by mlir-tblgen; don't manually edit */
#ifdef GEN_PASS_CLASSES

//===----------------------------------------------------------------------===//
// LLVMLegalizeForExport
//===----------------------------------------------------------------------===//

template <typename DerivedT>
class LLVMLegalizeForExportBase : public ::mlir::OperationPass<> {
public:
  LLVMLegalizeForExportBase() : ::mlir::OperationPass<>(::mlir::TypeID::get<DerivedT>()) {}
  LLVMLegalizeForExportBase(const LLVMLegalizeForExportBase &) : ::mlir::OperationPass<>(::mlir::TypeID::get<DerivedT>()) {}

  /// Returns the command-line argument attached to this pass.
  ::llvm::StringRef getArgument() const override { return "llvm-legalize-for-export"; }

  /// Returns the derived pass name.
  ::llvm::StringRef getName() const override { return "LLVMLegalizeForExport"; }

  /// Support isa/dyn_cast functionality for the derived pass class.
  static bool classof(const ::mlir::Pass *pass) {
    return pass->getTypeID() == ::mlir::TypeID::get<DerivedT>();
  }

  /// A clone method to create a copy of this pass.
  std::unique_ptr<::mlir::Pass> clonePass() const override {
    return std::make_unique<DerivedT>(*static_cast<const DerivedT *>(this));
  }

protected:
};
#undef GEN_PASS_CLASSES
#endif // GEN_PASS_CLASSES
#ifdef GEN_PASS_REGISTRATION
#define GEN_PASS_REGISTRATION_LLVMLegalizeForExport
#endif // GEN_PASS_REGISTRATION
#ifdef GEN_PASS_REGISTRATION_LLVMLegalizeForExport
::mlir::registerPass("llvm-legalize-for-export", "Legalize LLVM dialect to be convertible to LLVM IR", []() -> std::unique_ptr<::mlir::Pass> { return mlir::LLVM::createLegalizeForExportPass(); });
#endif // GEN_PASS_REGISTRATION_LLVMLegalizeForExport
#undef GEN_PASS_REGISTRATION_LLVMLegalizeForExport
#ifdef GEN_PASS_REGISTRATION
#undef GEN_PASS_REGISTRATION_LLVMLegalizeForExport
#endif // GEN_PASS_REGISTRATION
#undef GEN_PASS_REGISTRATION